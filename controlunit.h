// Implemented by Oleksandra Baga
#ifndef CONTROLUNIT_H
#define CONTROLUNIT_H

#include "opticalsensor.h"
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
#include "ingredient.h"
#include "pressuresensor.h"
#include "lcd_display.h"

#define NO_CUP_PROXIMITY 100

enum BrewStatus {
    BREW_NOT_STARTED,
    BREW_IN_PROGRESS,
    BREW_ERROR,
    BREW_DONE
};

class ControlUnit
{
    private:
        UserChoice *activeUserChoice;

        RFID_Scanner *RFID_s;
        OpticalSensor *opticalSensor;
        PressureSensor *pressureSensor;
        TemperaturSensor *temperatureSensor;
        Flowmeter *flow;

        LCD_Display *display;
        DC_Motor *motor[4];
        Waterheater *heater;
        Milkmaker *milkMaker;

        Brewgroup *brew;

    public:

        ControlUnit();

        void linkUserChoice(UserChoice *activeUserChoice);
        void connectRFID(RFID_Scanner *sensor);
        void connectOptical(OpticalSensor *sensor);
        void connectPressure(PressureSensor *sensor);
        void connectTemperatur(TemperaturSensor *sensor);
        void connectFlow(Flowmeter *sensor);

        void connectLCD(LCD_Display *actuator);
        void connectMotor(DC_Motor *actuator[4]);
        void connectHeater(Waterheater *actuator);
        void connectTemperatur(Milkmaker *actuator);


        bool checkCupHolder();
        bool checkCardHolder();

        void maintenanceRoutine();
        bool checkIngredients();
        void blockCapHolder();
        void abortPreparation();
        void prepareSelectedDrink();
        void unblockCupHolder();
        void writeFinalMessage();
        void writePreparationMessage();


};
extern ControlUnit control;

#endif // CONTROLUNIT_H
