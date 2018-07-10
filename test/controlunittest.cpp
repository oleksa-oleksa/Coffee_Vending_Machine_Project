#include "controlunittest.h"
#include "userchoice.h"

void ControlUnitTest::init()
{
    choice = new UserChoice();
    flow = new Flowmeter();
    opticalSensor = new OpticalSensor(flow);
    brightSensor = new BrightnessSensor();
    display = new LCD_Display();
    cardScanner = new RFID_Scanner();
    cu = new ControlUnit();

    cu->connectOptical(opticalSensor);
    cu->connectBrightnessSensor(brightSensor);
    cu->connectRFID(cardScanner);
    cu->connectFlow(flow);
    cu->connectLCD(display);

    activeUserChoice = this->choice;
}

void ControlUnitTest::cleanup()
{
    delete cardScanner;
    delete display;
    delete brightSensor;
    delete opticalSensor;
    delete flow;
    delete choice;
    delete cu;

    activeUserChoice = NULL;
}

void ControlUnitTest::testControlUnitInit()
{

    cu->onStartInit();

    QCOMPARE(choice->getSelectedDrink(), NO_DRINK);
    QCOMPARE(opticalSensor->getDistanceToObject(), 10);
    QCOMPARE(opticalSensor->getOpticalFlowSensorsMeasurements(), NO_CUP);
    QCOMPARE(brightSensor->getBrightness() < 3, display->getBacklight());
}

void ControlUnitTest::testCheckIngredients()
{
    Ingredient *tanks = cu->getIngredients();

    tanks->setCacaoIngredient(0);
    tanks->setCoffeeIngredient(0);
    tanks->setMilkIngredient(0);
    tanks->setSugarIngredient(0);

    // No ingredients needed for hot water
    activeUserChoice->setSelectedDrink(HOTWATER);
    QVERIFY(cu->checkIngredients());

    // Brewing with no ingredients is not possible
    activeUserChoice->setSelectedDrink(ESPRESSO);
    QCOMPARE(cu->checkIngredients(), false);

    // When there's enough ingredients, brewing is possible
    activeUserChoice->setSelectedDrink(CACAO);
    activeUserChoice->setMilkAmount(5);
    activeUserChoice->setSugarAmount(5);
    tanks->setMilkIngredient(100);
    tanks->setSugarIngredient(100);
    tanks->setCacaoIngredient(100);

    QCOMPARE(cu->checkIngredients(), true);

}

//         PreparationStatus checkStartConditions();
//         PreparationStatus prepareSelectedDrink();
//         void staffServiceRoutine();
//         bool checkSugarAmount();
// bool checkMilkAmount();
// bool checkCoffeeIngredient();
// bool checkCacaoIngredient();

