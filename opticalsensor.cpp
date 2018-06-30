// Exisiting file implemented for project by Oleksandra Baga
#include "opticalsensor.h"
#include <QDebug>

OpticalSensor::OpticalSensor()
{
    sensorType = OPTICAL;
    sensorState = UNDEFINED;
    isObjectDetected = false;
    distanceToObject = 10; // no object by default
}


OpticalSensor::~OpticalSensor()
{

}

bool OpticalSensor::getOpticalValue()
{
    // It is assumed that positive distanceToObject < 5 means the object is placed correctly
    // the distanceToObject > 5 means NO object was detected and isObjectDetected = false

    if (distanceToObject < 5)
    {
        isObjectDetected = true;
        qDebug() << "OPTICAL SENSOR: Object on correct distance is detected";
    }
    else
    {
        isObjectDetected = false;
        qDebug() << "OPTICAL SENSOR: Object on correct distance is not detected";

    }
    return isObjectDetected;
}

void OpticalSensor::setDistanceToObject(int distanceToObject)
{
    this->distanceToObject = distanceToObject;
}

int OpticalSensor::getDistanceToObject()
{
    return distanceToObject;
}


