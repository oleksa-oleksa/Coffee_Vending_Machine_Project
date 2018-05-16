#ifndef SENSOR_H
#define SENSOR_H
#include <string>
#include "sensortype.h"
#include "state.h"
using namespace std;

class Sensor
{
    SensorType sensor_type;
    State sensor_state; //new add

    public:
        Sensor();
        ~Sensor();
        SensorType getValue() const;
        SensorType getSensorType() const;
        bool getSensorState() const;
        void setSensorType(String type);
        void setSensorstate(enum State state);
        void setSensorType(string type);
        void setSensorstate(State state);
};

#endif // SENSOR_H
