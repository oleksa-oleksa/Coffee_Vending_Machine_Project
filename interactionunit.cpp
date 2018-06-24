// Created by Oleksandra Baga
#include "interactionunit.h"
#include <QtDebug>

InteractionUnit::InteractionUnit()
{

}

InteractionUnit::~InteractionUnit()
{

}

void InteractionUnit::buttonPollingRoutine()
{
    if (addSugar.getSensorState())
    {
        int newSugar = addSugar.getValue();
        choice->setExtraSugar(newSugar);
        qDebug() << "Selected: " << "Add more sugar: " << newSugar;
    }
    else if (removeSugar.getSensorState())
    {
        int newSugar = removeSugar.getValue();
        choice->setExtraSugar(newSugar);
        qDebug() << "Selected: " << "Remove sugar: " << newSugar;
    }
    else if (addMilk.getSensorState())
    {
        int newMilk = addMilk.getValue();
        choice->setExtraMilk(newMilk);
        qDebug() << "Selected: " << "Add more milk: " << newMilk;
    }
    else if (removeMilk.getSensorState())
    {
        int newMilk = removeMilk.getSensorState();
        choice->setExtraMilk(newMilk);
        qDebug() << "Selected: " << "Remove milk: " << newMilk;
    }
    else if (coffee.getSensorState())
    {
        choice->setSelectedDrink(COFFEE);
        qDebug() << "Selected: " << "COFFEE";
    }
    else if (cappuccino.getSensorState())
    {
        choice->setSelectedDrink(CAPPUCCINO);
        qDebug() << "Selected: " << "CAPPUCCINO";
    }
    else if (espresso.getSensorState())
    {
        choice->setSelectedDrink(ESPRESSO);
        qDebug() << "Selected: " << "ESPRESSO";
    }
    else if (latteMacchiato.getSensorState())
    {
        choice->setSelectedDrink(LATTEMACCHIOTO);
        qDebug() << "Selected: " << "LATTE MACCHIOTO";
    }
    else if (cacao.getSensorState())
    {
        choice->setSelectedDrink(CACAO);
        qDebug() << "Selected: " << "CACAO";
    }
    else if (hotWater.getSensorState())
    {
        choice->setSelectedDrink(HOTWATER);
        qDebug() << "Selected: " << "HOTWATER";
    }
    else if (bigPortion.getSensorState())
    {
        choice->toggleBigPortion();
        qDebug() << "Selected: " << "Big Portion";
    }
    else if (start.getSensorState())
    {
        choice->getPrice();
        qDebug() << "Price is set";
        if (choice->payDrink())
        {
            qDebug() << "Drink Paid";
        }
        else
        {
            qDebug() << "Payment failed";
        }
    }
}
