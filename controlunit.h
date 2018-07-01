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
#include "userchoice.h"

#define NO_CUP_PROXIMITY 100

enum BrewStatus {
    NOT_STARTED_FREE,
    IN_PROGRESS,
    BREW_ERROR,
    BREW_DONE
};

class ControlUnit
{
    private:
        UserChoice *activeUserChoice; // obtain components
                                   // from this pointer
                                    // sugar milk temperature...
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
        bool checkCard( Card& );
        // prepare drink with actuators and sensors!
        bool prepareSelectedDrink(UserChoice *selectedDrink);

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
