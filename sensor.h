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

        virtual SensorType getSensorType();
        virtual State getSensorState();
        virtual void setSensorType(SensorType);
        virtual void setSensorState(State);

        virtual void connetToControlUnit(SensorType sensor);


};

#endif // SENSOR_H
