// Implemented by Oleksandra Baga
#include "controlunit.h"

ControlUnit::ControlUnit()
{
    activeUserChoice = NULL;
}

void ControlUnit::linkUserChoice(UserChoice *activeUserChoice)
{
    qDebug() << "CONTROL_UNIT: UserChoice linked";
    this->activeUserChoice = activeUserChoice;
}
void ControlUnit::connectRFID(RFID_Scanner *sensor)
{
    RFID_s = sensor;
}
void ControlUnit::connectOptical(OpticalSensor *sensor)
{
    opticalSensor = sensor;
}
void ControlUnit::connectPressure(PressureSensor *sensor)
{
    pressureSensor = sensor;
}
void ControlUnit::connectTemperatur(TemperaturSensor *sensor)
{
    temperatureSensor = sensor;
}

void ControlUnit::connectFlow(Flowmeter *sensor)
{
    flow = sensor;
}

void ControlUnit::connectLCD(LCD_Display *actuator)
{
    display = actuator;
}
void ControlUnit::connectMotor(DC_Motor *actuator[4])
{
    motor[0] = actuator[0];
    motor[1] = actuator[1];
    motor[2] = actuator[2];
    motor[3] = actuator[3];
}
void ControlUnit::connectHeater(Waterheater *actuator)
{
    heater = actuator;
}
void ControlUnit::connectTemperatur(Milkmaker *actuator)
{
    milkMaker = actuator;
}


bool ControlUnit::checkCupHolder()
{

}

bool ControlUnit::checkIngredients()
{

}

bool ControlUnit::checkCardHolder()
{
    //return rfid.getRfidValidation(usercard);
}

void ControlUnit::maintenanceRoutine()
{
    checkIngredients();

// Set sensor and actuator states OK if UNDEFINED

    if (opticalSensor->getSensorState() == UNDEFINED)
        opticalSensor->setSensorState(OK);

    if (temperatureSensor->getSensorState() == UNDEFINED)
        temperatureSensor->setSensorState(OK);

    if (flow->getSensorState() == UNDEFINED)
        flow->setSensorState(OK);

    if (RFID_s->getSensorState() == UNDEFINED)
        RFID_s->setSensorState(OK);

    if (heater->getActuatorState() == UNDEFINED)
        heater->setActuatorState(OK);

    if (brew->getActuatorState() == UNDEFINED)
        brew->setActuatorState(OK);

    if (milkMaker->getActuatorState() == UNDEFINED)
        milkMaker->setActuatorState(OK);

    qDebug() << "ControlUnit: Checking ingredients and state done.";
}
