#include "temperatursensor.h"

TemperaturSensor::TemperaturSensor()
{
    sensorType = TEMPERATURE;
    sensorState = UNDEFINED;
    temperature = 0;
}


TemperaturSensor::TemperaturSensor(double setTemperature)
{
    sensorType = TEMPERATURE;
    sensorState = UNDEFINED;
    temperature = setTemperature;
}


TemperaturSensor::~TemperaturSensor()
{

}

double TemperaturSensor::getTemperature()
{
    return this->temperature;
}

