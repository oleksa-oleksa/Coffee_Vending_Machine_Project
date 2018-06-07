#include "pressuresensor.h"

PressureSensor::PressureSensor()
{
    sensorType = PRESSURE;
    sensorState = UNDEFINED;
    pressure = 0;
}

PressureSensor::PressureSensor(double setPressure)
{
    sensorType = PRESSURE;
    sensorState = UNDEFINED;
    pressure = setPressure;
}

PressureSensor::~PressureSensor()
{

}

double PressureSensor::getPressureValue()
{
    return this->pressure;
}
