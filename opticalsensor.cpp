#include "opticalsensor.h"

OpticalSensor::OpticalSensor()
{
    sensorType = OPTICAL;
    sensorState = UNDEFINED;
    isFree = false;
}


OpticalSensor::OpticalSensor(bool setIsFree)
{
    sensorType = OPTICAL;
    sensorState = UNDEFINED;
    isFree = setIsFree;
}


OpticalSensor::~OpticalSensor()
{

}

bool OpticalSensor::getOpticalValue()
{
    return this->isFree;
}

