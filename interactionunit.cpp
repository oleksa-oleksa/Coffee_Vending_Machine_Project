// Created by Oleksandra Baga
#include "interactionunit.h"
#include <QtDebug>

InteractionUnit::InteractionUnit() {
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

InteractionUnit::~InteractionUnit() {

}

UserChoice *InteractionUnit::initUserChoice(Card *card) {
    choice = new UserChoice(card);
    qDebug() << "INTERACTION_UNIT: UserChoice created";
    return choice;
}

void InteractionUnit::setMoreSugar(Button *moreSugar) {
    this->moreSugar = moreSugar;
}

void InteractionUnit::setLessSugar(Button *lessSugar) {
    this->lessSugar = lessSugar;
}

void InteractionUnit::setMoreMilk(Button *moreMilk) {
    this->moreMilk = moreMilk;
}

void InteractionUnit::setLessMilk(Button *lessMilk) {
    this->lessMilk = lessMilk;
}

void InteractionUnit::setCoffee(Button *coffee) {
    this->coffee = coffee;
}

void InteractionUnit::setCappuccino(Button *cappuccino) {
    this->cappuccino = cappuccino;
}

void InteractionUnit::setEspresso(Button *espresso) {
    this->espresso = espresso;
}

void InteractionUnit::setLatteMacchiato(Button *latteMacchiato) {
    this->latteMacchiato = latteMacchiato;
}

void InteractionUnit::setCacao(Button *cacao) {
    this->cacao = cacao;
}

void InteractionUnit::setHotWater(Button *hotWater) {
    this->hotWater = hotWater;
}
void InteractionUnit::setBigPortion(Button *bigPortion) {
    this->bigPortion = bigPortion;
}

void InteractionUnit::setStart(Button *start) {
    this->start = start;
}

void InteractionUnit::setCancel(Button *cancel)
{
    this->cancel = cancel;
}

Button *InteractionUnit::getMoreSugar() const {
    return moreSugar;
}

Button *InteractionUnit::getLessSugar() const {
    return lessSugar;
}

Button *InteractionUnit::getMoreMilk() const {
    return moreMilk;
}

Button *InteractionUnit::getLessMilk() const {
    return lessMilk;
}

Button *InteractionUnit::getCoffee() const {
    return coffee;
}

Button *InteractionUnit::getCappuccino() const {
    return cappuccino;
}

Button *InteractionUnit::getEspresso() const {
    return espresso;
}

Button *InteractionUnit::getLatteMacchiato() const {
    return latteMacchiato;
}

Button *InteractionUnit::getCacao() const {
    return cacao;
}

Button *InteractionUnit::getHotWater() const {
    return hotWater;
}

Button *InteractionUnit::getBigPortion() const {
    return bigPortion;
}

Button *InteractionUnit::getStart() const {
    return start;
}

void InteractionUnit::buttonPollingRoutine() {
    if (choice == NULL) {
        qDebug() << "LCD: Please insert valid card";
        return;
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

    if (choice && bigPortion && bigPortion->getButtonValue()) {
        if (choice->getBigPortion()) {
            choice->setDisabledBigPortion();
        }
        else {
            choice->setEnabledBigPortion();
        }
    }

    if (choice && cancel && cancel->getButtonValue()) {
        choice->setDefaultChoice();
    }

    if (choice && start && start->getButtonValue()) {
        choice->payDrink();
    }
}
