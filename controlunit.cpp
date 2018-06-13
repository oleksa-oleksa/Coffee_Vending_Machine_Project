#include "controlunit.h"

ControlUnit::ControlUnit()
{

}

bool ControlUnit::checkCup()
{
    if ( cupsensor.getProximity() < NO_CUP_PROXIMITY )
        return true;
    else
        return false;
}

bool ControlUnit::checkCard( Card& usercard )
{
    return rfid.getRfidValidation(usercard);
}

void ControlUnit::maintenanceRoutine()
{

}
