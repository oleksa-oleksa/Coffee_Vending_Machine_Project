#include "integrationtest01.h"
#include "controlunit.h"

void IntegrationTest01::testBrewingDrink()
{
    ControlUnit cu;

    UserChoice choice;
    Flowmeter flow;
    OpticalSensor opticalSensor(&flow);
    BrightnessSensor brightSensor;
    LCD_Display display;
    RFID_Scanner cardScanner;
    Waterheater heater;
    DC_Motor motors[MOTOR_TYPES_NUMBER];
    TemperaturSensor tempSensor;

    activeUserChoice = &choice;

    cu.connectOptical(&opticalSensor);
    cu.connectBrightnessSensor(&brightSensor);
    cu.connectRFID(&cardScanner);
    cu.connectFlow(&flow);
    cu.connectLCD(&display);
    cu.connectHeater(&heater);
    cu.connectTemperatur(&tempSensor);
    cu.connectMotor(motors, MOTOR_TYPES_NUMBER);

    Card::AllCards.push_back(Card());
    Card &c = Card::AllCards[0];
    Account a;
    Person o;

    c.setCardStatus(ACTIVE);
    c.setAccount(&a);
    a.setOwner(&o);

    cardScanner.insertCard(&c);

    activeUserChoice->setSelectedDrink(COFFEE);
    cu.prepareSelectedDrink();

    // Brewing heats water
    QVERIFY(heater.getCurrentTemperature() > 90);
    // ... uses ingredients
    QVERIFY(cu.getIngredients()->getCoffeeIngredient() < COFFEE_TANK_AMOUNT );
    // ... and finally pours drink into a cup
    QVERIFY(flow.getHasPreparedDrink());

}
