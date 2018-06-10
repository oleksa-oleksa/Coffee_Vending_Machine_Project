#include "milkmaker.h"
#include "actuator.h"

Milkmaker::Milkmaker()
{
    //actuator_duration =
    actuatorType = MILKMAKER;
    actuatorState = UNDEFINED;
}

Milkmaker::~Milkmaker()
{
  //to implement
}

bool Milkmaker::startStop(int status)
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















