#include "bestofNExp.h"
#include "bestofNEnv.h"
#include <QDebug>
#include <QThread>
#include <QTime>
#include <time.h>

// widgets
#include <QPushButton>
#include <QSlider>
#include <QGroupBox>
#include <QFormLayout>
#include <QLabel>
#include <QFrame>
#include <QCheckBox>
#include <QtMath>
#include <QSpinBox>
#include <QDir>
#include <QFileDialog>
#include <QSettings>
#include <QTableWidgetItem>
#include <QPainter>
#include <QComboBox>
#include <QVector3D>


// return pointer to interface!
// mykilobotexperiment can and should be completely hidden from the application
extern "C" BESTOFNEXPSHARED_EXPORT KilobotExperiment *createExpt()
{
    return new mykilobotexperiment();
}

mykilobotexperiment::mykilobotexperiment()
{
    // setup the environments here
    connect(&m_optionsEnv,SIGNAL(transmitKiloState(kilobot_message)), this, SLOT(signalKilobotExpt(kilobot_message)));
    connect(&m_DataRetrieval,SIGNAL(broadcastMessage(kilobot_broadcast)),this,SLOT(SendDataRetrievalProcessMessage(kilobot_broadcast)));
    this->serviceInterval = 100; // timestep in ms?
}

// GUI creation function: Working properly

QWidget * mykilobotexperiment::createGUI() {
    QFrame * frame = new QFrame;
    QVBoxLayout * lay = new QVBoxLayout;
    frame->setLayout(lay);

    /** Eperiment recording check box */
    QCheckBox * saveImages_ckb = new QCheckBox("Record experiment");
    saveImages_ckb->setChecked(true);// make the box not checked by default
    toggleSaveImages(saveImages_ckb->isChecked());

    lay->addWidget(saveImages_ckb);

    /** Experiment logging check box */
    QCheckBox * logExp_ckb = new QCheckBox("Log experiment");
    logExp_ckb->setChecked(true); // make the box checked by default
    toggleLogExp(logExp_ckb->isChecked());

    lay->addWidget(logExp_ckb);

    // signal-slot connections
    connect(saveImages_ckb, SIGNAL(toggled(bool)),this, SLOT(toggleSaveImages(bool)));
    connect(logExp_ckb, SIGNAL(toggled(bool)),this, SLOT(toggleLogExp(bool)));
    lay->addStretch();

    connect(this,SIGNAL(destroyed(QObject*)), lay, SLOT(deleteLater()));

    return frame;
}


// Initialization function: Working properly
void mykilobotexperiment::initialise(bool isResume) {

    m_log_period=1;
    m_optionsEnv.m_TimeForUpdatingVirtualSensors=false;

    m_optionsEnv.m_fCellLength=2000.0/m_optionsEnv.m_unGpsCells;
    qDebug() <<"Cell Length: " << m_optionsEnv.m_fCellLength;

    // Generate Environments:
    setupEnvironments();

    // Initialize Kilobot States:
    if (!isResume) {
        // init stuff
        emit getInitialKilobotStates();
    } else
    {

    }

    emit setTrackingType(POS | LED | ROT);

    QThread::currentThread()->setPriority(QThread::HighestPriority);

    savedImagesCounter = 0;
    this->m_time = 0;
    ElapsedTime.start();
    RTID_elapsedTime=0;
    RTID_wasActive=0;


    //save initial image
    if (saveImages) {
        emit saveImage(im_filename_prefix+im_filename_suffix.arg(savedImagesCounter++, 5,10, QChar('0')));
    }

    clearDrawings();
}

// Stop function working properly
void mykilobotexperiment::stopExperiment() {
    if (log_file.isOpen()){
        qDebug() << "Closing file" << log_file.fileName();
        log_file.close();
    }

    m_NumberOfConfigMsgsSent=0;
    RobotSpeaking=false;
    configurationMsgsSent=false;
    m_time=0;
    Trobot_last=0;
}

void mykilobotexperiment::run()
{
    if (saveImages) {
        emit saveImage(im_filename_prefix+im_filename_suffix.arg(savedImagesCounter++, 5,10, QChar('0')));
    }

    emit updateKilobotStates();

    // Update Broadcasting state
    UpdateBroadcastingState();

    // Send configuration messages
    if(m_NumberOfConfigMsgsSent < allKiloIDs.size() && !broadcasing)
    {

        kilobot_broadcast msg;
        msg.type=10; // Configuration message
        msg.data.resize(9);
        msg.data[0]= m_NumberOfConfigMsgsSent; // Robot ID

        QPointF robot_pos = allKilos[m_NumberOfConfigMsgsSent].position;
        int robot_x_GPS = m_optionsEnv.PositionToGPS(robot_pos).x();


        msg.data[1]= (uint8_t) robot_x_GPS; // Green area line Y
        msg.data[2]= (uint8_t) m_optionsEnv.m_area_green_y_low_GPS; // Green area line X
        msg.data[3]= (uint8_t) robot_x_GPS; // Green area line Y
        msg.data[4]= (uint8_t) m_optionsEnv.m_area_red_y_high_GPS; // Green area line X

//        qDebug() << "***************** BROADCAST MSG " << m_NumberOfConfigMsgsSent  << " **************** POS"<< robot_pos <<" ************* GPS" << robot_x_GPS;

        emit broadcastMessage(msg);

        broadcasing=true;
        t_since=3;

        m_NumberOfConfigMsgsSent++;

    }

    if ( configurationMsgsSent and (this->m_time - m_gps_last_time_sent)>= m_gps_sending_freq )
    {
        m_gps_last_time_sent = this->m_time;

        for(int i=0 ; i<m_optionsEnv.UpdateMessagingQueue.size(); i++)
        {
            m_optionsEnv.UpdateMessagingQueue[i]=true;

        }

//        qDebug() << "***************** TIME TO SEND GPS *****************" << this->m_time;

    }


    this->m_time=ElapsedTime.elapsed()/1000.0;
    m_optionsEnv.m_time=this->m_time;



    /* plot virtual environment */
    clearDrawings();
    clearDrawingsOnRecordedImage();
    plotEnvironment();

}


// Setup the Initial Kilobot Environment:
//   This is run once for each kilobot after emitting getInitialKilobotStates() signal.
//   This assigns kilobots to an environment.
void mykilobotexperiment::setupInitialKilobotState(Kilobot kilobotCopy) {

    // Assigns all kilobots to environment pheroEnv:
    this->setCurrentKilobotEnvironment(&m_optionsEnv);

    kilobot_id kID = kilobotCopy.getID();

    // create a necessary lists and variables
    if (kID > allKilos.size()-1)
    {
        allKilos.resize(kID+1);
        previousColourList.resize(kID+1);
        m_optionsEnv.m_requireGPS.resize(kID+1);
        m_optionsEnv.MessagingQueue.resize(kID+1);
        m_optionsEnv.UpdateMessagingQueue.resize(kID+1);
        m_optionsEnv.goingResamplingList.resize(kID+1);
    }

    KiloLog kLog(kID, kilobotCopy.getPosition(), 0, OFF);
    allKilos[kID] = kLog;
    previousColourList[kID] = OFF;
    if (!allKiloIDs.contains(kID)) allKiloIDs.append(kID);

}

// run once for each kilobot after emitting updateKilobotStates() signal
void mykilobotexperiment::updateKilobotState(Kilobot kilobotCopy) {

    kilobot_id kID = kilobotCopy.getID();
    QPointF kPos = kilobotCopy.getPosition();
    lightColour kColor=kilobotCopy.getLedColour();

    // update values for logging
    if (logExp){
        allKilos[kID].updateAllValues(kID, kPos, 0, kColor);
    }

}

// Setup Environment
void mykilobotexperiment::setupEnvironments( )
{

    m_optionsEnv.m_area_green_x_low = 1625 ;
    m_optionsEnv.m_area_green_y_low_GPS = 4;

    m_optionsEnv.m_area_red_x_high = 375 ;
    m_optionsEnv.m_area_red_y_high_GPS = 26 ;

    plotEnvironment();
}

// Draw the options:
void mykilobotexperiment::plotEnvironment()
{
    emit drawLine({cv::Point(0,m_optionsEnv.m_area_red_x_high),cv::Point(2000,m_optionsEnv.m_area_red_x_high)},QColor(255,0,0),8,"",true);
    emit drawLine({cv::Point(0,m_optionsEnv.m_area_green_x_low),cv::Point(2000,m_optionsEnv.m_area_green_x_low)},QColor(0,255,0),8,"",true);
}


void mykilobotexperiment::UpdateBroadcastingState()
{
    if(broadcasing){
        if(t_since>0){
            t_since--;
        }
        else {
            // STOP sending message
            kilobot_broadcast msg;
            msg.type = 250;
            emit broadcastMessage(msg);
            // Update broadcasting flag
            broadcasing=false;

            if(m_NumberOfConfigMsgsSent == allKilos.size() && !configurationMsgsSent ){
                configurationMsgsSent=true;
                qDebug() << "Done sending config messages!";
                qDebug() << "*********************************************";
            }
        }
    }
}

