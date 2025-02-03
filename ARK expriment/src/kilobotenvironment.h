#ifndef KILOBOTENVIRONMENT_H
#define KILOBOTENVIRONMENT_H

#include <QObject>
#include <QVector>
#include "kilobot.h"

class KilobotEnvironment : public QObject
{
    Q_OBJECT
public:
    explicit KilobotEnvironment(QObject *) {}
    KilobotEnvironment() {}

signals:
    void transmitKiloState(kilobot_message);

public slots:
    virtual void update() {}
    virtual void updateVirtualSensor(Kilobot) {} // Call this updateVirtualSensor(...)


};

#endif // KILOBOTENVIRONMENT_H
