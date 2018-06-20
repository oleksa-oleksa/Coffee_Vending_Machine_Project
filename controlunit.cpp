#include "controlunit.h"

ControlUnit::ControlUnit()
{

}

bool ControlUnit::checkCup()
{
    if ( cupsensor.getProximity() < NO_CUP_PROXIMITY )
    {
        qDebug() << "Cup detected";
        return true;
    }
    else
    {
        qDebug() << "No Cup detected";
        return false;
    }
}

bool ControlUnit::checkIngredients()
{
// Get fillevels for Debug
    if ( fillevel[0].getOpticalValue() )
        qDebug() << "Sugar empty";
     if ( fillevel[1].getOpticalValue() )
        qDebug() << "Milk empty";
    if ( fillevel[2].getOpticalValue() )
        qDebug() << "Coffee empty: ";
    if ( fillevel[3].getOpticalValue() )
        qDebug() << "Cacao empty:  ";

// Return false if one is empty
    for (int i=0; i<3; i++)
    {
        if (fillevel[i].getOpticalValue())
            return false;
    }

}

bool ControlUnit::checkCard( Card& usercard )
{
    return rfid.getRfidValidation(usercard);
}

void ControlUnit::maintenanceRoutine()
{
    checkIngredients();

// Set sensor and actuator states OK if UNDEFINED
    for (int i=0; i<3; i++)
    {
        if (fillevel[i].getSensorState() == UNDEFINED)
            fillevel[i].setSensorstate(OK);
        if (motor[i].getActuatorState() == UNDEFINED)
            motor[i].setActuatorState(OK);
    }

    if (cupsensor.getSensorState() == UNDEFINED)
        cupsensor.setSensorstate(OK);

    if (temp.getSensorState() == UNDEFINED)
        temp.setSensorstate(OK);

    if (flow.getSensorState() == UNDEFINED)
        flow.setSensorstate(OK);

    if (rfid.getSensorState() == UNDEFINED)
        rfid.setSensorstate(OK);

    if (heater.getActuatorState() == UNDEFINED)
        heater.setActuatorState(OK);

    if (brew.getActuatorState() == UNDEFINED)
        brew.setActuatorState(OK);

    if (milk.getActuatorState() == UNDEFINED)
        milk.setActuatorState(OK);

    qDebug() << "ControlUnit: Checking ingredients and state done."
}
