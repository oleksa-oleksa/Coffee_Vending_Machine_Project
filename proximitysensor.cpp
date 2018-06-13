#include "proximitysensor.h"

ProximitySensor::ProximitySensor()
{
    sensorType = PROXIMITY;
    sensorState = UNDEFINED;
    proximity = 0;

}

ProximitySensor::ProximitySensor(double setProximity)
{
    sensorType = PROXIMITY;
    sensorState = UNDEFINED;
    proximity = setProximity;

}

ProximitySensor::~ProximitySensor()
{

}

double ProximitySensor::getProximity()
{
    return this->proximity;
}

