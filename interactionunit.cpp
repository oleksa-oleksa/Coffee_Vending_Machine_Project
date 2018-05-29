#include "interactionunit.h"
#include <QtDebug>

InteractionUnit::InteractionUnit()
{

}

void InteractionUnit::ButtonPollingRoutine()
{
    if (addSugar.getSensorState())
    {
        int newSugar = addSugar.getValue();
        choice->setExtraSugar(newSugar);
        Debug() << "Selected: " << "Add more sugar:" << newSugar;
    }
    else if (removeSugar.getSensorState())
    {
        int newSugar = removeSugar.getValue();
        choice->setExtraSugar(newSugar);
        Debug() << "Selected: " << "Remove sugar:" << newSugar;
    }
    else if (addMilk.getSensorState())
    {
        int newMilk = addMilk.getValue();
        choice->setMilkQuantity(newMilk);
        Debug() << "Selected: " << "Add more milk:" << newMilk;
    }
    else if (removeMilk.getSensorState())
    {
        int newMilk = removeMilk.getSensorState();
        choice->setMilkQuantity(newMilk);
        Debug() << "Selected: " << "Remove milk:" << newMilk;
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
        Debug() << "Selected: " << "CACAO";
    }
    else if (hotWater.getSensorState())
    {
        choice->setSelectedDrink(HOTWATER);
        Debug() << "Selected: " << "HOTWATER";
    }
    else if (bigPortion.getSensorState())
    {
        choice->setBigPortion(true);
        Debug() << "Selected: " << "Big Portion";
    }
    else if (start.getSensorState())
    {
        choice->setPrice();
        qDebug() << "Price is set";
        choice->payDrink();
        Debug() << "Drink Paid";
    }
}
