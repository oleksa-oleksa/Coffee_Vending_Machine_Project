#include "sensor.h"

Sensor::Sensor()
{

}

Sensor::~Sensor()
{

}

SensorType Sensor::getvalue() const
{
   return sensor_type;
}

SensorType Sensor::getSensorType() const
{
    return sensor_type;
}

bool Sensor::getSensorState() const //??? why bool and not SensorState?
{
    if(sensor_state == OK || sensor_state == IS_EVENT || sensor_state == ALARM || sensor_state == UNDEFINED)
        return true;
    else
        return false;
}

void Sensor::setSensorType(String type)
{
    sensor_type = type;
}

void Sensor::setSensorstate(enum State state)
{
    sensor_state = state;
}
