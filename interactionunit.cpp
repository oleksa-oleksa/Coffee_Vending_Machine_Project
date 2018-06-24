// Created by Oleksandra Baga
#include "interactionunit.h"
#include <QtDebug>

InteractionUnit::InteractionUnit()
{

}

InteractionUnit::~InteractionUnit()
{

}

void InteractionUnit::setAddSugar(Button *addSugar)
{
    this->addSugar = addSugar;
}
void InteractionUnit::setRemoveSugar(Button *removeSugar)
{
    this->removeSugar = removeSugar;
}
void InteractionUnit::setAddMilk(Button *addMilk)
{
    this->addMilk = addMilk;
}
void InteractionUnit::setRemoveMilk(Button *removeMilk)
{
    this->removeMilk = removeMilk;
}
void InteractionUnit::setCoffee(Button *coffee)
{
    this->coffee = coffee;
}
void InteractionUnit::setCappuccino(Button *cappuccino)
{
    this->cappuccino = cappuccino;
}
void InteractionUnit::setEspresso(Button *espresso)
{
    this->espresso = espresso;
}
void InteractionUnit::setLatteMacchiato(Button *latteMacchiato)
{
    this->latteMacchiato = latteMacchiato;
}
void InteractionUnit::setCacao(Button *cacao)
{
    this->cacao = cacao;
}
void InteractionUnit::setHotWater(Button *hotWater)
{
    this->hotWater = hotWater;
}
void InteractionUnit::setBigPortion(Button *bigPortion)
{
    this->bigPortion = bigPortion;
}
void InteractionUnit::setStart(Button *start)
{
    this->start = start;
}

Button *InteractionUnit::getAddSugar()
{
    return addSugar;
}
Button *InteractionUnit::getRemoveSugar()
{
    return removeSugar;
}
Button *InteractionUnit::getAddMilk()
{
    return addMilk;
}
Button *InteractionUnit::getRemoveMilk()
{
    return removeMilk;
}
Button *InteractionUnit::getCoffee()
{
    return coffee;
}
Button *InteractionUnit::getCappuccino()
{
    return cappuccino;
}
Button *InteractionUnit::getEspresso()
{
    return espresso;
}
Button *InteractionUnit::getLatteMacchiato()
{
    return latteMacchiato;
}
Button *InteractionUnit::getCacao()
{
    return cacao;
}
Button *InteractionUnit::getHotWater()
{
    return hotWater;
}
Button *InteractionUnit::getBigPortion()
{
    return bigPortion;
}
Button *InteractionUnit::getStart()
{
    return start;
}

UserChoice *InteractionUnit::initUserChoice(Card *card)
{
    choice = new UserChoice(card);
    return choice;
}

void InteractionUnit::buttonPollingRoutine()
{
    if (choice == NULL)
    {
        qDebug() << "LED: Please insert valid card";
        return;
    }

    if (addSugar->getSensorState()) {
        choice->setExtraSugar(choice->getExtraSugar()+1);
    }

}
