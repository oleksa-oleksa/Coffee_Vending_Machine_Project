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
#include "card.h"
#include <QDebug>

#define NO_CUP_PROXIMITY 100

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
/* For testing:
        RFID_Scanner testRfidScanner;
        RFID_Scanner& rfid = testRfidScanner;
*/

        bool checkIngredients();
        bool checkCup();
        bool checkCard( Card& );

        ControlUnit();
        ControlUnit(ControlUnit const&);              // Don't Implement.
        ControlUnit& operator=(ControlUnit const&); // Don't implement

    public:

        static ControlUnit& getInstance()
        {
            static ControlUnit instance;
            return instance;
        }

        void maintenanceRoutine();
};

#endif // CONTROLUNIT_H
