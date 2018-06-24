// Created by Oleksandra Baga
#include "userchoicetest.h"
#include "drinktype.h"

void UserChoiceTest::testPayDrink()
{
    // All Object and dependencies
    // THE RIGHT ORDER TO GET ACCESS FOR PAYMENT
    Account ts_acc01;
    Person ts_per01;
    AccountID ts_acid01;
    ts_acc01.setAccountID(ts_acid01);
    ts_acc01.setOwner(&ts_per01);
    Account::AllAccounts.push_back(ts_acc01);

    Card test01(&ts_acc01);
    test01.linkAccount(ts_acid01);

    UserChoice choice01(&test01);

    DrinkType dt01 = CACAO;
    DrinkType dt02 = COFFEE;
    DrinkType dt03 = NO_DRINK;
    qDebug() << "01:";
    choice01.setSelectedDrink(dt01);
    choice01.getPrice();
    QCOMPARE(choice01.payDrink(), true);

    qDebug() << "02:";
    choice01.setSelectedDrink(dt02);
    choice01.getPrice();
    QCOMPARE(choice01.payDrink(), true);

    qDebug() << "03:";
    choice01.setSelectedDrink(dt03);
    choice01.getPrice();
    QCOMPARE(choice01.payDrink(), false);
}

void UserChoiceTest::testSetSelectedDrink()
{
    DrinkType dt01 = CAPPUCCINO;
    DrinkType dt02 = HOTWATER;
    DrinkType dt03 = NO_DRINK;

    // All Object and dependencies
    // THE RIGHT ORDER TO GET ACCESS FOR PAYMENT
    Account ts_acc01;
    Person ts_per01;
    AccountID ts_acid01;
    ts_acc01.setAccountID(ts_acid01);
    ts_acc01.setOwner(&ts_per01);
    Account::AllAccounts.push_back(ts_acc01);

    Card test01(&ts_acc01);
    test01.linkAccount(ts_acid01);

    UserChoice choice01(&test01);

    qDebug() << "Selected Drink after object creation";
    choice01.getSelectedDrink();

    qDebug() << "01:";
    choice01.setSelectedDrink(dt01);
    choice01.getSelectedDrink();
    qDebug() << "02:";
    choice01.setSelectedDrink(dt02);
    choice01.getSelectedDrink();
    qDebug() << "03:";
    choice01.setSelectedDrink(dt03);
    choice01.getSelectedDrink();
}

void UserChoiceTest::testGetPrice()
{
    DrinkType dt01 = CAPPUCCINO;
    DrinkType dt02 = HOTWATER;
    DrinkType dt03 = NO_DRINK;

    // All Object and dependencies
    // THE RIGHT ORDER TO GET ACCESS FOR PAYMENT
    Account ts_acc01;
    Person ts_per01;
    AccountID ts_acid01;
    ts_acc01.setAccountID(ts_acid01);
    ts_acc01.setOwner(&ts_per01);
    Account::AllAccounts.push_back(ts_acc01);

    Card test01(&ts_acc01);
    test01.linkAccount(ts_acid01);

    UserChoice choice01(&test01);

    qDebug() << "Price after object creation";
    choice01.getPrice();

    qDebug() << "01:";
    choice01.setSelectedDrink(dt01);
    choice01.getPrice();
    qDebug() << "02:";
    choice01.setSelectedDrink(dt02);
    choice01.getPrice();
    qDebug() << "03:";
    choice01.setSelectedDrink(dt03);
    choice01.getPrice();
}
