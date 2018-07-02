#include "sensor.h"

Sensor::Sensor()
{

}

Sensor::~Sensor()
{

}

SensorType Sensor::getSensorType()
{
    qDebug() << "Sensor Type:" << sensorType;
    return sensorType;
}

State Sensor::getSensorState()
{
    qDebug() << "Sensor State:" << sensorType;
    return sensorState;
}

void Sensor::setSensorType(SensorType newType)
{
    if (newType != NULL)
        sensorType = newType;
}

void Sensor::setSensorState(State newState)
{
    if (sensorState != NULL)
        sensorState = newState;
}

void Sensor::connetToControlUnit(SensorType sensor)
{
    switch (sensor) {

    //case (RFID):

    }
}
