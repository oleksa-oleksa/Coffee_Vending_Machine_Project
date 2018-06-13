#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include "sensortype.h"
#include "state.h"

class Sensor
{
    protected:
        SensorType sensorType;
        State sensorState;
        //Sensor(SensorType type, State state) : sensorType(type), sensorState(state) {}

    public:
        Sensor();
        virtual ~Sensor();

        virtual SensorType getSensorType();
        virtual State getSensorState();
        virtual void setSensorType(SensorType);
        virtual void setSensorstate(State);


};

#endif // SENSOR_H
