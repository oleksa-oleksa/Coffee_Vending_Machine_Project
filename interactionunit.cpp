#include "interactionunit.h"

InteractionUnit::InteractionUnit()
{

}

void InteractionUnit::ButtonPollingRoutine()
{
    if (addSugar.getSensorState())
    {
        int newSugar = addSugar.getValue();
        choice->setExtraSugar(newSugar);
    }
    else if (removeSugar.getSensorState())
    {
        int newSugar = removeSugar.getValue();
        choice->setExtraSugar(newSugar);
    }
    else if (addMilk.getSensorState())
    {
        int newMilk = addMilk.getValue();
        choice->setMilkQuantity(newMilk);
    }
    else if (removeMilk.getSensorState())
    {
        int newMilk = removeMilk.getSensorState();
        choice->setMilkQuantity(newMilk);
    }
    else if (coffee.getSensorState())
    {
        choice->setSelectedDrink(COFFEE);
    }
    else if (cappuccino.getSensorState())
    {
        choice->setSelectedDrink(CAPPUCCINO);
    }
    else if (espresso.getSensorState())
    {
        choice->setSelectedDrink(ESPRESSO);
    }
    else if (latteMacchiato.getSensorState())
    {
        choice->setSelectedDrink(LATTEMACCHIOTO);
    }
    else if (cacao.getSensorState())
    {
        choice->setSelectedDrink(CACAO);
    }
    else if (hotWater.getSensorState())
    {
        choice->setSelectedDrink(HOTWATER);
    }
    else if (bigPortion.getSensorState())
    {
        choice->setBigPortion(true);
    }
}
