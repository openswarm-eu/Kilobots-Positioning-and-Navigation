#include "bestofNEnv.h"
#include <QVector>
#include <QLineF>
#include <QDebug>
#include <QtMath>

#include "kilobot.h"

mykilobotenvironment::mykilobotenvironment(QObject *parent) : KilobotEnvironment(parent) {
    qDebug() << "Environment is up and running. :-)";
}

// Update the dynamic environment:
void mykilobotenvironment::update()
{

}


// generate virtual sensor readings & send to KB
void mykilobotenvironment::updateVirtualSensor(Kilobot kilobot) {
    kilobot_id kID = kilobot.getID();
    QPointF kPos = kilobot.getPosition();
    
    //     qDebug() << "UpdateMessagingQueue: " << UpdateMessagingQueue[kID];
    
    if(UpdateMessagingQueue[kID])
    {
        UpdateMessagingQueue[kID]=false;

        kilobot_message msg;

        unsigned int m_message_type;

        // Get robot's GPS coordinates
        QPoint GPS_cords=PositionToGPS(kPos);
        uint8_t GPS_y = 31-GPS_cords.y();

//        qDebug() << "----------------> SEDING GPS MESSAGE TO ROBOT <----------------" << kID << " GPS_y " << GPS_y;
        // Set msg type
        m_message_type=0; // 0->GPS 1->Discovery
        // Get robot's orientation
        double orientDegrees = qRadiansToDegrees(qAtan2(-kilobot.getVelocity().y(),kilobot.getVelocity().x()));
        orientDegrees=desNormAngle(orientDegrees);
        msg.id=kID<<2 | m_message_type<<1 | ( (uint8_t) GPS_cords.x() ) >> 4;
        msg.type= ( (uint8_t) GPS_cords.x() ) & 0x0F;
        msg.data= ( (uint8_t) ( GPS_y )  ) << 5 | ( (uint8_t) (orientDegrees/12.0) );
        emit transmitKiloState(msg);
    }
}


QPoint mykilobotenvironment::PositionToGPS(QPointF position){
    return QPoint((unsigned int) std::ceil(position.x()/m_fCellLength )-1, (unsigned int) std::ceil(position.y()/m_fCellLength )-1);
}

float mykilobotenvironment::desNormAngle(float angle){
    while (angle > 360) angle = angle - 360;
    while (angle < 0) angle = 360 + angle;
    return angle;
}
