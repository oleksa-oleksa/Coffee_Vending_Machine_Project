#include "userchoice.h"
#include "drinktype.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

UserChoice::UserChoice(Card *card) : UserChoice()
{
    this->card = card;
}

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
        return (card->withdraw(price));
        qDebug() << "payDrink() finished.";
    }
}

void UserChoice::setSelectedDrink(DrinkType selectedDrink)
{
    this->selectedDrink = selectedDrink;
    QString str = printSelectedDrink();
    qDebug() << "SETTER: Selected Drink is set: " << str;
}

DrinkType UserChoice::getSelectedDrink()
{
    QString str = printSelectedDrink();
    qDebug() << "GETTER: Selected Drink is: " << str;
    return selectedDrink;
}

void UserChoice::setCard(Card *card)
{
    this->card = card;
}

Card *UserChoice::getCard()
{
    return card;
}


void UserChoice::setExtraSugar(int extraSugar)
{
    this->extraSugar = extraSugar;
}

int UserChoice::getExtraSugar()
{
    return extraSugar;
}

void UserChoice::setExtraMilk(int extraMilk)
{
    this->extraMilk = extraMilk;
}

int UserChoice::getExtraMilk()
{
    return extraMilk;
}

// setter
void UserChoice::toggleBigPortion()
{
    isBigPortion = !isBigPortion;
}

bool UserChoice::getBigPortion()
{
    return isBigPortion;
}

double UserChoice::getPrice()
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
    else
    {
        price = 0;
    }
    QString str = printSelectedDrink();
    qDebug() << "Price for the drink " << str << "is " << price;
    return price;
}

QString UserChoice::printSelectedDrink()
{
    QString str;
    switch (selectedDrink) {
    case NO_DRINK:
            str = "NO_DRINK";
            return str;
    case COFFEE:
            str = "COFFEE";
            return str;
    case CAPPUCCINO:
            str = "CAPPUCCINO";
            return str;
    case ESPRESSO:
            str = "ESPRESSO";
            return str;
    case LATTEMACCHIOTO:
            str = "LATTEMACCHIOTO";
            return str;
    case CACAO:
            str = "CACAO";
            return str;
    case HOTWATER:
            str = "HOTWATER";
            return str;
    default:
        break;
    }

}
