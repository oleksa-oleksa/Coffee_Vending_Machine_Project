#ifndef SENSOR_H
#define SENSOR_H

#include "sensortype.h"

class Sensor
{
    public:
        Sensor();
        ~Sensor();
        SensorType getValue() const;
        SensorType getSensorType() const;
        bool getSensorState() const;
        void setSensorType(String type);
        void setSensorstate(enum State state);

    private:
        SensorType sensor_type;
};

#endif // SENSOR_H
