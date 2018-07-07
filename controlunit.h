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
#include "card.h"
#include "brightnesssensor.h"
#include "interactionunit.h"

#define AMOUNT_OF_MOTORS 4
#define MINIMAl_THRESHOLD 5


class ControlUnit
{
    private:
        InteractionUnit *iunit;

        RFID_Scanner *cardScanner;
        Flowmeter *flow;
        OpticalSensor *opticalSensor;
        PressureSensor *pressureSensor;
        TemperaturSensor *temperatureSensor;
        BrightnessSensor *brightSensor;

        LCD_Display *display;
        DC_Motor *motor[4];
        Waterheater *heater;
        Milkmaker *milkMaker;

        Brewgroup *brew;
        Ingredient *ingredientTanks;

    public:

        ControlUnit();
        ~ControlUnit();

        void linkInteractionUnit(InteractionUnit *iunit);

        void setDisplayBacklight();
        void onStartInit();
        bool checkCardReader();
        bool checkCard();
        CardHolderState insertCard(Card *card);
        CupHolderState checkCupHolder();
        void writeMessageLCD(LCD_Message message, PreparationStatus status);
        void writeMessageLCD(LCD_Message message);


        void maintenanceRoutine();
        bool checkIngredients();
        PreparationStatus checkStartConditions();
        void blockCupHolder();
        void abortPreparation();
        PreparationStatus prepareSelectedDrink();
        void unblockCupHolder();
        void staffServiceRoutine();
        bool checkSugarAmount();
        bool checkMilkAmount();
        bool checkCoffeeIngredient();
        bool checkCacaoIngredient();

        bool isBrewingFinished();

        void connectRFID(RFID_Scanner *sensor);
        void connectFlow(Flowmeter *sensor);
        void connectOptical(OpticalSensor *sensor);
        void connectPressure(PressureSensor *sensor);
        void connectTemperatur(TemperaturSensor *sensor);
        void connectBrightnessSensor(BrightnessSensor *sensor);

        void connectLCD(LCD_Display *actuator);
        void connectMotor(DC_Motor *actuator, int numOfActuators);
        void connectHeater(Waterheater *actuator);
        void connectMilkMaker(Milkmaker *actuator);
        void connectBrewGroup(Brewgroup *actuator);

        Ingredient *getIngredients();
};
extern ControlUnit control;

#endif // CONTROLUNIT_H
