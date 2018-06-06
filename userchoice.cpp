#include "userchoice.h"
#include "drinktype.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

UserChoice::UserChoice()
{
    selectedDrink = NO_DRINK;
    extraSugar = 0;
    extraMilk = 0;
    isBigPortion = false;
    price = 0.0;
}

bool UserChoice::payDrink()
{
    if (selectedDrink == NO_DRINK)
    {
        qDebug() << "LCD: Please select a drink first!";
        return false;
    }
    else
    {
        // Paying
        return (card.withdraw(price));
        qDebug() << "payDrink() finished.";
    }
}

DrinkType UserChoice::setSelectedDrink(DrinkType drink)
{
    selectedDrink = drink;
    qDebug() << "Drink is set: " << selectedDrink;
    return selectedDrink;
}

void UserChoice::setExtraSugar(int sugar)
{
    extraSugar = sugar;
    qDebug() << "Extra sugar is set: " << extraSugar;
}

void UserChoice::setMilkQuantity(int milkQuantity)
{
    extraMilk = milkQuantity;
    qDebug() << "Extra milk is set: " << extraMilk;
}

void UserChoice::toggleBigPortion()
{
    isBigPortion = !isBigPortion;
    qDebug() << "Big Portion is set: " << isBigPortion;
}

double UserChoice::setPrice()
{
    if (selectedDrink == COFFEE)
    {
        price = 0.80;
    }
    else if (selectedDrink == CAPPUCCINO)
    {
        price = 0.90;
    }
    else if (selectedDrink == ESPRESSO)
    {
        price = 1.20;
    }
    else if (selectedDrink == LATTEMACCHIOTO)
    {
        price = 1.40;
    }
    else if (selectedDrink == CACAO)
    {
        price = 1.40;
    }
    else if (selectedDrink == HOTWATER)
    {
        price = 0.20;
    }
    else if (selectedDrink == NO_DRINK)
    {
        price = 0;
    }

    qDebug() << "Price for the drink " << selectedDrink << "is " << price;
    return price;
}
