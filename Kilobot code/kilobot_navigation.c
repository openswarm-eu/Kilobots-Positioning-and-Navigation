#include "kilolib.h"
//#define DEBUG
//#include "debug.h" // for real robots only
//#include <stdio.h> // for ARGOS only
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define PI 3.14159265358979323846

/* Enum for different motion types */
typedef enum {
    STOP = 0,
    FORWARD,
    TURN_LEFT,
    TURN_RIGHT,
} motion_t;

/* Enum for boolean flags */
typedef enum {
    false = 0,
    true = 1,
} bool;


/* current motion type */
motion_t current_motion_type = STOP;

/* current LED color */
uint16_t current_LED_color=RGB(0,0,0);


unsigned int turning_ticks = 0;
const uint8_t max_turning_ticks = 150; /* constant to allow a maximum rotation of 180 degrees with \omega=\pi/5 */
const uint32_t max_straight_ticks = 300;
uint32_t last_motion_ticks = 0;
uint32_t update_ticks = 60; /* setting how often performing the commitment update. a tick here is every ~31ms */
uint32_t last_update_ticks = 0;

/* Variables for outgoing messages */
message_t message;


/* Variables for incoming messages from ARK */
uint8_t RED_GOAL_GPS_X;
uint8_t RED_GOAL_GPS_Y;
uint8_t GREEN_GOAL_GPS_X;
uint8_t GREEN_GOAL_GPS_Y;


/* Robot GPS variables */
uint8_t Robot_GPS_X;
uint8_t Robot_GPS_Y;
double Robot_orientation;
bool new_sa_msg_gps=false;

/* Robot Goal variables*/
uint8_t Goal_GPS_X;
uint8_t Goal_GPS_Y;

/* Wall Avoidance manouvers */
uint32_t wallAvoidanceCounter=0; // to decide when the robot is stuck...

/* Options lookup table*/


/* RTID variables */
bool runtime_identification=false;
uint32_t backup_kiloticks;
uint16_t backup_LED;
motion_t backup_motion=STOP;


float RotSpeed=38.0;

uint8_t GPS_maxcell=16;
uint8_t minDist=4;

float GPS_To_Meter=1/16.0;
float Robot_FoV=0.0;


bool debug_state=false;
uint32_t debug_lastTableUpdate = 0;
uint8_t debug_lastAssignedID = 0;
uint8_t debug_lastSource = 0;


bool goals_set = false;


/*-------------------------------------------------------------------*/
/* Compute angle to Goal                                             */
/*-------------------------------------------------------------------*/
void NormalizeAngle(double* angle)
{
    while(*angle>180){
        *angle=*angle-360;
    }
    while(*angle<-180){
        *angle=*angle+360;
    }
}


/*-------------------------------------------------------------------*/
/* Compute angle to Goal                                             */
/*-------------------------------------------------------------------*/
double AngleToGoal() {
    NormalizeAngle(&Robot_orientation);
    double angletogoal=atan2(Goal_GPS_Y-Robot_GPS_Y,Goal_GPS_X-Robot_GPS_X)/PI*180-Robot_orientation;
    NormalizeAngle(&angletogoal);
    return angletogoal;
}


/*-------------------------------------------------------------------*/
/* Function for setting the motor speed                              */
/*-------------------------------------------------------------------*/
void set_motion( motion_t new_motion_type ) {
    if( current_motion_type != new_motion_type )
    {
        current_motion_type = new_motion_type;

        int calibrated = true;
        switch( new_motion_type )
        {
        case FORWARD:
            if(!runtime_identification)
                spinup_motors();
            if (calibrated){

                if(!runtime_identification)
                    set_motors(kilo_straight_left,kilo_straight_right);
            }
            else
            {
                if(!runtime_identification)
                    set_motors(67,67);
            }
            break;
        case TURN_LEFT:
            if(!runtime_identification)
                spinup_motors();
            if (calibrated)
            {
                if(!runtime_identification) {
                    uint8_t leftStrenght = kilo_turn_left;
                    uint8_t i;
                    for (i=3; i <= 18; i += 3){
                        if (wallAvoidanceCounter >= i){
                            leftStrenght+=2;
                        }
                    }
                    set_motors(leftStrenght,0);
                    //                    set_motors(kilo_turn_left,0);
                }
            }
            else{
                if(!runtime_identification)
                    set_motors(70,0);
            }
            break;
        case TURN_RIGHT:
            if(!runtime_identification)
                spinup_motors();
            if (calibrated){
                if(!runtime_identification) {
                    uint8_t rightStrenght = kilo_turn_right;
                    uint8_t i;
                    for (i=3; i <= 18; i += 3){
                        if (wallAvoidanceCounter >= i){
                            rightStrenght+=2;
                        }
                    }
                    set_motors(0,rightStrenght);
                    //                    set_motors(0,kilo_turn_right);
                }
            }
            else{
                if(!runtime_identification)
                    set_motors(0,70);
            }
            break;
        case STOP:
        default:
            set_motors(0,0);
        }

        if(current_motion_type!=STOP){
            backup_motion=current_motion_type;
        }
    }
}


/*-------------------------------------------------------------------*/
/* Function for setting the new goal                                 */
/* (including LED colour and message initialisation)                 */
/*-------------------------------------------------------------------*/
void set_goal( uint8_t new_goal_GPS_X, uint8_t new_goal_GPS_Y)
{
    Goal_GPS_X = new_goal_GPS_X;
    Goal_GPS_Y = new_goal_GPS_Y;
}


/*-------------------------------------------------------------------*/
/* Init function                                                     */
/*-------------------------------------------------------------------*/
void setup()
{
    /* Initialise commitment and LED */
    //    set_commitment(0 , 0 , 0);

    /* Initialise motors */
    set_motors(0,0);
    kilo_ticks=0;

    /* Initialise random seed */
    uint8_t seed = rand_hard();
    rand_seed(seed);
    seed = rand_hard();
    srand(seed);

    //    /* Initialise motion variables */
    set_motion( STOP );
    last_motion_ticks = rand() % max_straight_ticks + 1;

    //    /* Initialise broadcast variables */
    //    last_broadcast_ticks = rand() % broadcast_ticks + 1;

    //    /** Initialise update variables */
    //    last_update_ticks= rand() % update_ticks;


    //    /* Intialize time to 0 */
    //    kilo_ticks=0;

    /* initialise the GSP to the middle of the environment, to avoid to trigger wall avoidance immediately */
    Robot_GPS_X = GPS_maxcell/2;
    Robot_GPS_Y = GPS_maxcell/2;
}


/*-------------------------------------------------------------------*/
/* Callback function for message reception                           */
/*-------------------------------------------------------------------*/
void message_rx( message_t *msg, distance_measurement_t *d ) {
    /** ARK MESSAGE **/
    if (msg->type == 0) {

        // unpack message
        int id1 = msg->data[0];
        int id2 = msg->data[3];
        int id3 = msg->data[6];
        unsigned int sa_type;

        if (id1 == kilo_uid) {
            // unpack type
            sa_type = msg->data[1] >> 7;
            if(sa_type==0){
                // unpack payload
                Robot_GPS_X = msg->data[1]>>2 & 0x1F;
                Robot_GPS_Y = (msg->data[1] & 0x03)<< 3 | msg->data[2]>>5 ;
                Robot_orientation = (msg->data[2] & 0x1F)*12;

//                if (Robot_GPS_Y == 26)
//                    set_color(RGB(3,3,3));

                //                printf("My GPS coords are: ( %d , %d ) \n", Robot_GPS_X , Robot_GPS_Y);
                //                printf("My orientation is: %f\n", Robot_orientation);
                new_sa_msg_gps = true;
            }

        }
        if (id2 == kilo_uid) {
            sa_type = msg->data[4] >> 7;
            if(sa_type==0){
                // unpack payload
                Robot_GPS_X = msg->data[4]>>2 & 0x1F;
                Robot_GPS_Y = (msg->data[4] & 0x03)<< 3 | msg->data[5]>>5 ;
                Robot_orientation = (msg->data[5] & 0x1F)*12;
                new_sa_msg_gps = true;

//                if (Robot_GPS_Y == 26)
//                    set_color(RGB(3,3,3));

            }
        }
        if (id3 == kilo_uid) {
            sa_type = msg->data[7] >> 7;
            if(sa_type==0){
                // unpack payload
                Robot_GPS_X = msg->data[7]>>2 & 0x1F;
                Robot_GPS_Y = (msg->data[7] & 0x03)<< 3 | msg->data[8]>>5 ;
                Robot_orientation = (msg->data[8] & 0x1F)*12;
                new_sa_msg_gps = true;

//                if (Robot_GPS_Y == 26)
//                    set_color(RGB(3,3,3));
            }
        }

    }


    /** ARK Config File **/
    else if (msg->type == 10) {

        if (msg->data[0] == kilo_uid)
        {
            //            set_color(RGB(3,3,3));
            GREEN_GOAL_GPS_X = msg->data[1];
            GREEN_GOAL_GPS_Y = msg->data[2];

            RED_GOAL_GPS_X = msg->data[3];
            RED_GOAL_GPS_Y = msg->data[4];

            //            if (RED_GOAL_GPS_Y == 26)
            //                set_color(RGB(3,3,3));

            set_goal(RED_GOAL_GPS_X,RED_GOAL_GPS_Y);

            //            if (Goal_GPS_Y == Goal_GPS_Y)
            //            {
            set_color(RGB(3,0,0));
            //            }

            goals_set = true;
            set_motion( FORWARD );
        }
    }
    /** ARK ID identification **/
    else if (msg->type == 120) {
        int id = (msg->data[0] << 8) | msg->data[1];
        if (id == kilo_uid) {
            set_color(RGB(0,0,3));
        } else {
            set_color(RGB(3,0,0));
        }
    }
    /** ARK Runtime identification **/
    else if (msg->type == 119) {
        // runtime identification
        int id = (msg->data[0] << 8) | msg->data[1];
        if (id >= 0){ // runtime identification ongoing
            set_motion(STOP);
            runtime_identification = true;
            if (id == kilo_uid) {
                set_color(RGB(0,0,3));
            } else {
                set_color(RGB(3,0,0));
            }
        } else { // runtime identification ended
            kilo_ticks=backup_kiloticks;
            //set_color(current_LED_color);
            runtime_identification = false;
            set_motion(backup_motion);
        }
    }

}

void CheckAreasSensor(){
    if(new_sa_msg_gps)
    {
        //        new_sa_msg_gps=false;
        if (Goal_GPS_Y == RED_GOAL_GPS_Y && Robot_GPS_Y >= RED_GOAL_GPS_Y)
        {
            set_goal(GREEN_GOAL_GPS_X,GREEN_GOAL_GPS_Y);
            set_color(RGB(0,3,0));
        }

        if (Goal_GPS_Y == GREEN_GOAL_GPS_Y && Robot_GPS_Y <= GREEN_GOAL_GPS_Y)
        {
            set_goal(RED_GOAL_GPS_X,RED_GOAL_GPS_Y);
            set_color(RGB(3,0,0));
        }
    }
}
/*-------------------------------------------------------------------*/
/* Function to go to the Goal location (e.g. to resample an option)  */
/*-------------------------------------------------------------------*/
void GoToGoalLocation(){
    if(new_sa_msg_gps){
        new_sa_msg_gps=false;

        double angleToGoal = AngleToGoal();
        if(fabs(angleToGoal) <= 20)
        {
            set_motion(FORWARD);
            last_motion_ticks = kilo_ticks;
        }
        else{
            if(angleToGoal>0){
                set_motion(TURN_LEFT);
                last_motion_ticks = kilo_ticks;
                turning_ticks=(unsigned int) ( fabs(angleToGoal)/RotSpeed*32.0 );
                //                    debug_print("In need to turn left for: %d\n", turning_ticks );
            }
            else{
                set_motion(TURN_RIGHT);
                last_motion_ticks = kilo_ticks;
                turning_ticks=(unsigned int) ( fabs(angleToGoal)/RotSpeed*32.0 );
                //                    debug_print("In need to turn right for: %d\n", turning_ticks );
            }
        }
    }

    switch( current_motion_type ) {    //    debug_init();

    case TURN_LEFT:
        if( kilo_ticks > last_motion_ticks + turning_ticks ) {
            /* start moving forward */
            last_motion_ticks = kilo_ticks;  // fixed time FORWARD
            //	last_motion_ticks = rand() % max_straight_ticks + 1;  // random time FORWARD
            set_motion(FORWARD);
        }
        break;
    case TURN_RIGHT:
        if( kilo_ticks > last_motion_ticks + turning_ticks ) {
            /* start moving forward */
            last_motion_ticks = kilo_ticks;  // fixed time FORWARD
            //	last_motion_ticks = rand() % max_straight_ticks + 1;  // random time FORWARD
            set_motion(FORWARD);
        }
        break;
    case FORWARD:
        break;

    case STOP:
    default:
        set_motion(STOP);
    }

}


/*-------------------------------------------------------------------*/
/* Main loop                                                         */
/*-------------------------------------------------------------------*/
void loop() {

    if (goals_set)
    {
        CheckAreasSensor();
        GoToGoalLocation();
    }
}


/*-------------------------------------------------------------------*/
/* Main function                                                     */
/*-------------------------------------------------------------------*/
int main()
{
    kilo_init();
    //    debug_init();
    kilo_message_rx=message_rx;
    kilo_start(setup, loop);
    return 0;
}
