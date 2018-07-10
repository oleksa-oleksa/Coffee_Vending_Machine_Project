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

