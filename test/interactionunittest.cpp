// Created by Oleksandra Baga
#include "interactionunittest.h"
#include "interactionunit.h"
#include "button.h"
#include "userchoice.h"
#include "card.h"

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


#define TRIGGER(button) ({button.setSensorstate(PRESSED); \
                          iunit.buttonPollingRoutine();\
                          button.setSensorstate(RELEASED);})

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

    // At this point no user choice was initialized
    // Calling buttonPoillingRoutine must quit without an effect
    iunit.buttonPollingRoutine();

    UserChoice *userChoice;

    userChoice = iunit.initUserChoice(&test_card);

    // Simulate "add sugar" click

    //    addSugar.setSensorstate(PRESSED);
    //    iunit.buttonPollingRoutine();
    //    addSugar.setSensorstate(RELEASED);

    //    triggerButton(iunit, addSugar);

    TRIGGER(addSugar);

    QCOMPARE(userChoice->getExtraSugar(), 1);


/*
    UserChoice *choce02; // Just hot water

*/
}
