#include "led.h"

LED::LED()
{
    //actuator_duration;
    actuatorType = Led;
    actuatorState = UNDEFINED;
}

LED::~LED()
{

}

bool LED::startStop(int status)
{
    if(status)
    {
        return true;
    }
    else
    {
        return false;
    }
}










