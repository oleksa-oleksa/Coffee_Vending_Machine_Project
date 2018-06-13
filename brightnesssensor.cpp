#include "brightnesssensor.h"

BrightnessSensor::BrightnessSensor()
{
    sensorType = BRIGHTNESS;
    sensorState = UNDEFINED;
    brightness = 0;
}

BrightnessSensor::BrightnessSensor(unsigned int setBrightness)
{
    sensorType = BRIGHTNESS;
    sensorState = UNDEFINED;
    brightness = setBrightness;
}

BrightnessSensor::~BrightnessSensor()
{

}

unsigned int BrightnessSensor::getBrightness()
{
    return this->brightness;
}
