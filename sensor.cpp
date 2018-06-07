#include "sensor.h"

Sensor::Sensor()
{

}

Sensor::~Sensor()
{

}

SensorType Sensor::getSensorType()
{
    return sensorType;
}

State Sensor::getSensorState()
{
    return sensorState;
}

void Sensor::setSensorType(SensorType newType)
{
    if (newType != NULL)
        sensorType = newType;
}

void Sensor::setSensorstate(State newState)
{
    if (sensorState != NULL)
        sensorState = newState;
}
