// Created by Oleksandra Baga
// System Test for Coffee Vending Machine Project
#include "systemtest.h"
#include "interactionunit.h"
#include "userchoice.h"
#include "button.h"
#include "lcd_display.h"
#include "opticalsensor.h"
#include "flowmeter.h"
#include "controlunit.h"


SystemTest::SystemTest() : QObject(), opticalSensor(&flow)
{


}

void SystemTest::cleanup()
{
    Person::AllEmployee.clear();
    BankAccount::AllBankAccounts.clear();
    Account::AllAccounts.clear();
    Card::AllCards.clear();
}

void SystemTest::systemTest() {

    createAllDependencies();

    Card *card = &Card::AllCards[0];

    display.writeDefaultText(activeUserChoice);
    QCOMPARE(display.getTitle(), "Please insert card");
    QCOMPARE(display.getDrinkName(),"NO_DRINK");
    QCOMPARE(display.getPrice(), 0.0);

    //=============================================================
    // Simulate INSERT CARD
    // Now there is no card and this code should set isCardInside = true and isChoiceAllowed = true

    QCOMPARE(control.insertCard(card), VALID_CARD_INSIDE);

    //=============================================================
    // Simulated: Card is inserted, name and greeting
    // no price and no selected drink name


    // Sumulation: Select "Coffee"
    coffee.setSensorState(PRESSED);
    iunit.buttonPollingRoutine();
    coffee.setSensorState(RELEASED);
    display.writeUserChoiceText(activeUserChoice);

    QCOMPARE(activeUserChoice->getSelectedDrink(), COFFEE);

    // variables for automatic testing and compare
    int  expected_sugar = activeUserChoice->getSugarAmount();
    int expected_milk = activeUserChoice->getMilkAmount();
    float expected_price = activeUserChoice->getPrice();

    // Decrease default sugar amount by 1
    lessSugar.setSensorState(PRESSED);
    iunit.buttonPollingRoutine();
    lessSugar.setSensorState(RELEASED);
    display.writeUserChoiceText(activeUserChoice);

    QCOMPARE(activeUserChoice->getSugarAmount(), expected_sugar - 1);


    // Increase default milk amount by 1 + 1
    // Button pressed for the first time
    moreMilk.setSensorState(PRESSED);
    iunit.buttonPollingRoutine();
    moreMilk.setSensorState(RELEASED);
    display.writeUserChoiceText(activeUserChoice);

    QCOMPARE(activeUserChoice->getMilkAmount(), expected_milk + 1);

    // Button pressed for the second time
    moreMilk.setSensorState(PRESSED);
    iunit.buttonPollingRoutine();
    moreMilk.setSensorState(RELEASED);
    display.writeUserChoiceText(activeUserChoice);

    QCOMPARE(activeUserChoice->getMilkAmount(), expected_milk + 2);

    // Choose Big Portion
    QCOMPARE(activeUserChoice->getBigPortion(), false);
    bigPortion.setSensorState(PRESSED);
    iunit.buttonPollingRoutine();
    bigPortion.setSensorState(RELEASED);
    display.writeUserChoiceText(activeUserChoice);
    QCOMPARE(activeUserChoice->getBigPortion(), true);


    // User has selected a drink and pushes the Start Button:
    // But he has forgot to place a cup!
    QCOMPARE(control.checkStartConditions(), PREPARE_ERROR_NO_CUP);

    // Place cup
    opticalSensor.setDistanceToObject(2);
    QCOMPARE(control.checkCupHolder(), EMPTY_CUP);

    // starting againg
    opticalSensor.setDistanceToObject(2);
    QCOMPARE(control.checkStartConditions(), PREPARE_IS_ALLOWED);

    display.writeWaitText();
    control.blockCupHolder();

    QCOMPARE(control.prepareSelectedDrink(), PREPARE_DONE);

    control.unblockCupHolder();
    display.writeTakeDrinkMessage();

    // checking credit. Verification accounts to inexact floating point value representation
    QVERIFY(activeAccount->getAccountCredit()-expected_price < 0.00001);

    // eject card
    cardScanner.ejectCard();
    delete(activeUserChoice);
}

void SystemTest::createAllDependencies() {

    // Creating all dependencies
    // Firstly, we will start with a card provided by user into RFID
    Card::AllCards.push_back(Card());
    Account::AllAccounts.push_back(Account());
    Person::AllEmployee.push_back(Person());
    BankAccount::AllBankAccounts.push_back(BankAccount());

    Card *card = &Card::AllCards[0];
    Account *account = &Account::AllAccounts[0];

    account->setOwner(&Person::AllEmployee[0]);
    account->setBankAccount(&BankAccount::AllBankAccounts[0]);

    card->setAccount(account);
    // Thus we can find out which account belongs to the card
    activeAccount = card->getAccount();

    // and what the person interacts with Vending Machine
    activePerson = card->getAccount()->getOwner();

    // and which bank account is connected to the card for withdrawing process
    bankAccount = card->getAccount()->getBankAccount();

    if (activeUserChoice) {
        delete activeUserChoice;
    }

    // activeUserChoice has the selected drink with  price and recipe
    // the information for preparation will be transfered to ControlUnit with "Start" button
    activeUserChoice = iunit.initUserChoice(card);

    //======================================================================
    // and finaly: UserChoice initialisation in InteractionUnit in order
    // to track all interactions with buttons
    // This solution based on UML Diagramm created for the University Course
    iunit.setMoreSugar(&moreSugar);
    iunit.setLessSugar(&lessSugar);
    iunit.setMoreMilk(&moreMilk);
    iunit.setLessMilk(&lessMilk);
    iunit.setCoffee(&coffee);
    iunit.setCappuccino(&cappuccino);
    iunit.setEspresso(&espresso);
    iunit.setLatteMacchiato(&latteMacchiato);
    iunit.setCacao(&cacao);
    iunit.setHotWater(&hotWater);
    iunit.setBigPortion(&bigPortion);
    iunit.setCancel(&cancel);
    iunit.setStart(&start);

    // links to ControlUnit
    control.linkInteractionUnit(&iunit);

    // Connect the sensors
    control.connectRFID(&cardScanner);
    control.connectFlow(&flow);
    control.connectOptical(&opticalSensor);
    control.connectTemperatur(&temperatureSensor);
    control.connectBrightnessSensor(&brightSensor);

    // connect the actuators
    control.connectLCD(&display);
    control.connectMotor(&motor[0], 4);
    control.connectHeater(&heater);
    control.connectMilkMaker(&milkMaker);

     // check sensors and actuators
    control.maintenanceRoutine();
    control.onStartInit();
}
