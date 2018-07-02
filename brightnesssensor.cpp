#include <ctime>
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
  time_t t = time(0);
  tm *now = localtime(&t);

  // Sensor will be darkened between
  // - 16:00 and 9:00 from November 1st till March 31st
  // - 20:00 and 7:00 from April 1st till September 30th

  if ((now->tm_mon >= 10 || now->tm_mon < 3) &&
      (now->tm_hour >= 15 || now->tm_hour < 8)){
    // It's winter night
    return 2;
  } else if ((now->tm_mon >= 3 && now->tm_mon < 10) &&
      (now->tm_hour >= 19 || now->tm_hour < 7)) {
    // It's summer night
    return 2;
  }

  return 6; // Otherwise it's bright

}
