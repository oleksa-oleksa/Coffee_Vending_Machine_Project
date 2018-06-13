#include "dc_motor.h"

DC_Motor::DC_Motor()
{
    //this->actuator_duration =
    actuatorState = UNDEFINED;
    actuatorType = DC_MOTOR;

}

DC_Motor::~DC_Motor()
{

}

bool DC_Motor:: startStop(int status)
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
