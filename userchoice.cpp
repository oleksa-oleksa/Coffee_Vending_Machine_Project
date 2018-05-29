#include "userchoice.h"
#include "drinktype.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

UserChoice::UserChoice() : selectedDrink(NO_DRINK),
                           card(),
                           extraSugar(0),
                           extraMilk(0),
                           isBigPortion(false),
                           price(0.0)
{  
}

bool UserChoice::payDrink()
{
    if (price == 0)
    {
        printf("Please make a choice first!\n");
    }
    else
    {

    }
}

DrinkType UserChoice::getProgramButtonState()
{

}

int UserChoice::getSugarButtonState()
{

}

int UserChoice::getMilkButtonState()
{

}

bool UserChoice::getOKButtonState()
{

}

DrinkType UserChoice::setSelectedDrink(DrinkType drink)
{
    selectedDrink = drink;
    return selectedDrink;
}

void UserChoice::setExtraSugar(int sugar)
{
    extraSugar = sugar;
}

void UserChoice::setMilkQuantity(int milkQuantity)
{
    extraMilk = milkQuantity;
}

void UserChoice::setBigPortion(bool isBig)
{
    isBigPortion = isBig;
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
