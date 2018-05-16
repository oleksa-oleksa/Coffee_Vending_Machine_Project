#ifndef SENSOR_H
#define SENSOR_H
#include "sensortype.h"

class Sensor
{
    SensorType sensor_type;

    public:
        Sensor();
        ~Sensor();
        SensorType getValue() const;
        SensorType getSensorType() const;
        bool getSensorState() const;
        void setSensorType(String type);
        void setSensorstate(enum State state);
};

#endif // SENSOR_H
