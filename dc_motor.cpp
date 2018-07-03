#include "dc_motor.h"

DC_Motor::DC_Motor()
{
    actuatorState = UNDEFINED;
    actuatorType = DC_MOTOR;
}

DC_Motor::~DC_Motor()
{

}

void DC_Motor::rotate(int miliseconds)
{
    stopRotationAt = time(0) + miliseconds;
}

bool DC_Motor::isRotating()
{
    if (stopRotationAt - time(0) > 0) {
        return false;
    }
    else {
        stopRotationAt = 0;
        return true;
    }
}
