// Created by Oleksandra Baga
#include "interactionunittest.h"
#include "interactionunit.h"
#include "button.h"
#include "userchoice.h"
#include "card.h"

// FOR TEST PURPOSE TO AVOID EXTRA LOC
#define TRIGGER_BUTTON(button) ({button.setSensorstate(PRESSED); \
                          iunit.buttonPollingRoutine();\
                          button.setSensorstate(RELEASED);})


void InteractionUnitTest::testInitUserChoice()
{
    Card card;

    // Sample is a UserChoice instance initialized with a default constructor
    UserChoice sample;
    UserChoice *user; // this object will be created inside InteractionUnit

    InteractionUnit inter;
    user = inter.initUserChoice(&card);

    QCOMPARE(user->getSelectedDrink(), sample.getSelectedDrink());
    QCOMPARE(user->getPrice(), sample.getPrice());
    QCOMPARE(user->getCard(), &card);
}



void InteractionUnitTest::testButtonPollingRoutine()
{

    Card test_card;
    InteractionUnit iunit;

    Button addSugar, removeSugar, addMilk,
           removeMilk, coffee, cappuccino,
           espresso, latteMacchiato, cacao,
           hotWater, bigPortion, start;

    iunit.setAddSugar(&addSugar);
    iunit.setRemoveSugar(&removeSugar);
    iunit.setAddMilk(&addMilk);
    iunit.setRemoveMilk(&removeMilk);

    // At this point no user choice was initialized
    // Calling buttonPoillingRoutine must quit without an effect
    iunit.buttonPollingRoutine();

    // UserChoise is now initialised, drink can be modified
    UserChoice *userChoice;
    userChoice = iunit.initUserChoice(&test_card);

    // SIMULATION
    // COFFEF WITH 4 ADDITIONAL SUGAR
    // NO MILK AT ALL
    // BIG PORTION

    // Simulate "coffee" click: sugar 3, milk 3
    userChoice->setSelectedDrink(COFFEE);

    // Simulate "add sugar" click: sugar 4
    TRIGGER_BUTTON(addSugar);

    // simulate milk 3 => milk 0
    TRIGGER_BUTTON(removeMilk);
    TRIGGER_BUTTON(removeMilk);
    TRIGGER_BUTTON(removeMilk);

    QCOMPARE(userChoice->getSelectedDrink(), COFFEE);
    QCOMPARE(userChoice->getExtraSugar(), 4);
    QCOMPARE(userChoice->getExtraMilk(), 0);
    QCOMPARE(userChoice->getPrice(), 0.90);



/*
    UserChoice *choce02; // Just hot water

*/
}
