// Exisiting file implemented for project by Oleksandra Baga
#include "opticalsensor.h"
#include <QDebug>

OpticalSensor::OpticalSensor()
{
    sensorType = OPTICAL;
    sensorState = UNDEFINED;
    isObjectDetected = false;
    distanceToObject = 10; // no object by default
    flow = NULL;
}

OpticalSensor::OpticalSensor(Flowmeter *flow)
{
    sensorType = OPTICAL;
    sensorState = UNDEFINED;
    isObjectDetected = false;
    distanceToObject = 10; // no object by default
    this->flow = flow;
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

    }
    else
    {
        isObjectDetected = false;
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

// Main Function to obtain the state of cup holder
// we need two sensors for three states: no cup, empty cup, cup with drink
CupHolderState OpticalSensor::getOpticalFlowSensorsMeasurements()
{
    // if cup detected
    if (getOpticalValue())
    {
        // and a drink was prepared
        if (flow->getHasPreparedDrink())
        {
            qDebug() << "OPTICAL SENSOR: There is a full cup";
            return FULL_CUP;
        }

        // only cup stays and no drink was prepared
        else
        {
            qDebug() << "OPTICAL SENSOR: There is an empty cup";
            return EMPTY_CUP;
        }
    }
    // there is not cup and no drink
    else
    {
        qDebug() << "OPTICAL SENSOR: Cup holder is empty";
        return NO_CUP;
    }
}
