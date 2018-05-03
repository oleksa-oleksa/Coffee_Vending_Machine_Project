#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include "opticalsensor.h"
#include "proximitysensor.h"
#include "dc_motor.h"
#include "temperatursensor.h"
#include "waterheater.h"
#include "flowmeter.h"
#include "brewgroup.h"
#include "milkmaker.h"
#include "rfid_scanner.h"

class ControlUnit
{
    private:
        OpticalSensor fillevel[4];
        ProximitySensor cupsensor;
        DC_Motor motor[4];
        TemperaturSensor temp;
        Waterheater heater;
        Flowmeter flow;
        Brewgroup brew;
        Milkmaker milk;
        RFID_Scanner rfid;

        bool checkIngredients();
        bool checkCup();
        bool checkCard();

    public:
        ControlUnit();
        void maintenanceRoutine();
};

#endif // CONTROLUNIT_H
