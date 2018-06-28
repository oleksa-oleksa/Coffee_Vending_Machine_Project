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

InteractionUnit *InteractionUnit::initInteractionUnit(Button *moreSugar,
                                                      Button *lessSugar,
                                                      Button *moreMilk,
                                                      Button *lessMilk,
                                                      Button *coffee,
                                                      Button *cappuccino,
                                                      Button *espresso,
                                                      Button *latteMacchiato,
                                                      Button *cacao,
                                                      Button *hotWater,
                                                      Button *bigPortion,
                                                      Button *cancel,
                                                      Button *start)
{
    InteractionUnit *unt_unit;

    unt_unit->moreSugar = moreSugar;
    unt_unit->lessSugar = lessSugar;
    unt_unit->moreMilk = moreMilk;
    unt_unit->lessMilk = lessMilk;
    unt_unit->coffee = coffee;
    unt_unit->cappuccino = cappuccino;
    unt_unit->espresso = espresso;
    unt_unit->latteMacchiato = latteMacchiato;
    unt_unit->cacao = cacao;
    unt_unit->hotWater = hotWater;
    unt_unit->bigPortion = bigPortion;
    unt_unit->cancel = cancel;
    unt_unit->start = start;

    return unt_unit;
}

UserChoice *InteractionUnit::initUserChoice(Card *card)
{
    choice = new UserChoice(card);
    return choice;
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

void InteractionUnit::setCancel(Button *cancel)
{
    this->cancel = cancel;
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

void InteractionUnit::buttonPollingRoutine()
{
    if (choice == NULL)
    {
        qDebug() << "LCD: Please insert valid card";
        return;
    }

    if (choice->getSelectedDrink() == NO_DRINK)
    {
        return;
    }

    if (choice && moreSugar && moreSugar->getButtonValue()) {
        choice->setSugarAmount(choice->getSugarAmount() + 1);
    }

    if (choice && lessSugar && lessSugar->getButtonValue()) {
        choice->setSugarAmount(choice->getSugarAmount() - 1);
    }

    if (choice && moreMilk && moreMilk->getButtonValue()) {
        choice->setMilkAmount(choice->getMilkAmount() + 1);
    }

    if (choice && lessMilk && lessMilk->getButtonValue()) {
        choice->setMilkAmount(choice->getMilkAmount() - 1);
    }

    if (choice && coffee && coffee->getButtonValue()) {
        choice->setSelectedDrink(COFFEE);
    }

    if (choice && cappuccino && cappuccino->getButtonValue()) {
        choice->setSelectedDrink(CAPPUCCINO);
    }

    if (choice && espresso && espresso->getButtonValue()) {
        choice->setSelectedDrink(ESPRESSO);
    }

    if (choice && latteMacchiato && latteMacchiato->getButtonValue()) {
        choice->setSelectedDrink(LATTEMACCHIOTO);
    }

    if (choice && cacao && cacao->getButtonValue()) {
        choice->setSelectedDrink(CACAO);
    }

    if (choice && hotWater && hotWater->getButtonValue()) {
        choice->setSelectedDrink(HOTWATER);
    }

    if (choice && bigPortion && bigPortion->getButtonValue()) {
        choice->toggleBigPortion();
    }

    if (choice && cancel && cancel->getButtonValue()) {
        choice->setDefaultChoice();
    }

    if (choice && start && start->getButtonValue()) {
        choice->payDrink();
    }

}
