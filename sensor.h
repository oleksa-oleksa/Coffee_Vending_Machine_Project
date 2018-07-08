#ifndef SENSOR_H
#define SENSOR_H

#include <QDebug>
#include <string>
#include "sensortype.h"
#include "state.h"

class Sensor
{
    protected:
        SensorType sensorType;
        State sensorState;

    public:
        Sensor();
        virtual ~Sensor();

        virtual SensorType getSensorType() const;
        virtual State getSensorState() const;
        virtual void setSensorType(SensorType);
        virtual void setSensorState(State);

        QString printSensorState();
        QString printSensorType();

};

#endif // SENSOR_H
