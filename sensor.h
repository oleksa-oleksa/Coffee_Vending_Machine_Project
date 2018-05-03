#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include "sensortype.h"
#include "state.h"

class Sensor
{
    public:
        Sensor();
        ~Sensor();
        SensorType getValue() const;
        SensorType getSensorType() const;
        bool getSensorState() const;
        void setSensorType(std::string type);
        void setSensorstate(State state);

    private:
        SensorType sensor_type;
};

#endif // SENSOR_H
