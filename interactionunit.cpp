// Created by Oleksandra Baga
#include "interactionunit.h"
#include <QtDebug>

InteractionUnit::InteractionUnit()
{
    choice = NULL;

    moreSugar = NULL;
    lessSugar = NULL;
    moreMilk = NULL;
    lessMilk = NULL;
    coffee = NULL;
    cappuccino = NULL;
    espresso = NULL;
    latteMacchiato = NULL;
    cacao = NULL;
    hotWater = NULL;
    bigPortion = NULL;
    cancel = NULL;
    start = NULL;
}

InteractionUnit::~InteractionUnit()
{

}

void InteractionUnit::setMoreSugar(Button *moreSugar)
{
    this->moreSugar = moreSugar;
}
void InteractionUnit::setLessSugar(Button *lessSugar)
{
    this->lessSugar = lessSugar;
}
void InteractionUnit::setMoreMilk(Button *moreMilk)
{
    this->moreMilk = moreMilk;
}
void InteractionUnit::setLessMilk(Button *lessMilk)
{
    this->lessMilk = lessMilk;
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

Button *InteractionUnit::getMoreSugar()
{
    return moreSugar;
}
Button *InteractionUnit::getLessSugar()
{
    return lessSugar;
}
Button *InteractionUnit::getMoreMilk()
{
    return moreMilk;
}
Button *InteractionUnit::getLessMilk()
{
    return lessMilk;
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
        qDebug() << "LCD: Please insert valid card";
        return;
    }

    if (moreSugar && moreSugar->getButtonValue()) {
        choice->setSugarAmount(choice->getSugarAmount() + 1);
    }

    if (lessSugar && lessSugar->getButtonValue()) {
        choice->setSugarAmount(choice->getSugarAmount() - 1);
    }

    if (moreMilk && moreMilk->getButtonValue()) {
        choice->setMilkAmount(choice->getMilkAmount() + 1);
    }

    if (lessMilk && lessMilk->getButtonValue()) {
        choice->setMilkAmount(choice->getMilkAmount() - 1);
    }

    if (coffee && coffee->getButtonValue()) {
        choice->setSelectedDrink(COFFEE);
    }

    if (cappuccino && cappuccino->getButtonValue()) {
        choice->setSelectedDrink(CAPPUCCINO);
    }

    if (espresso && espresso->getButtonValue()) {
        choice->setSelectedDrink(ESPRESSO);
    }

    if (latteMacchiato && latteMacchiato->getButtonValue()) {
        choice->setSelectedDrink(LATTEMACCHIOTO);
    }

    if (cacao && cacao->getButtonValue()) {
        choice->setSelectedDrink(CACAO);
    }

    if (hotWater && hotWater->getButtonValue()) {
        choice->setSelectedDrink(HOTWATER);
    }

    if (bigPortion && bigPortion->getButtonValue()) {
        choice->toggleBigPortion();
    }

    if (cancel && cancel->getButtonValue()) {
        choice->setDefaultChoice();
    }

    if (start && start->getButtonValue()) {
        choice->payDrink();
    }

}
