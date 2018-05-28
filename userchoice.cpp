#include "userchoice.h"
#include "drinktype.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

UserChoice::UserChoice() : selectedDrink(NO_DRINK),
                           card(),
                           extraSugar(0),
                           extraMilk(0),
                           isBigPortion(false),
                           price(0.0)
{  
}

bool UserChoice::payDrink(double price)
{

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
