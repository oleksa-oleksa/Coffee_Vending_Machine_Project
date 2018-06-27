#include "userchoice.h"
#include "drinktype.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include "coffee.h"
#include "cappuccino.h"
#include "espresso.h"
#include "lattemacchiato.h"
#include "cacao.h"
#include "hotwater.h"

UserChoice::UserChoice(Card *card) : UserChoice()
{
    this->card = card;
}

UserChoice::UserChoice()
{
    setDefaultChoice();
}

void UserChoice::setDefaultChoice()
{
    selectedDrink = NO_DRINK;
    sugarAmount = 0;
    milkAmount = 0;
    isBigPortion = false;
    hotWaterAmount = 0;
    recipeTemperature = 0;
    specificRecipeComponent = 0;
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

    if (selectedDrink == COFFEE)
    {
        Coffee drink;
        sugarAmount = drink.getSugarAmount();
        milkAmount = drink.getMilkAmount();
        hotWaterAmount = drink.getHotWaterAmount();
        recipeTemperature = drink.getRecipeTemperature();
        specificRecipeComponent = drink.getRecipeIngredient();
        price = drink.getPrice();
    }

    else if (selectedDrink == CAPPUCCINO)
    {
        Cappuccino drink;
        sugarAmount = drink.getSugarAmount();
        milkAmount = drink.getMilkAmount();
        hotWaterAmount = drink.getHotWaterAmount();
        recipeTemperature = drink.getRecipeTemperature();
        specificRecipeComponent = drink.getRecipeIngredient();
        price = drink.getPrice();
    }
    else if (selectedDrink == ESPRESSO)
    {
        Espresso drink;
        sugarAmount = drink.getSugarAmount();
        milkAmount = drink.getMilkAmount();
        hotWaterAmount = drink.getHotWaterAmount();
        recipeTemperature = drink.getRecipeTemperature();
        specificRecipeComponent = drink.getRecipeIngredient();
        price = drink.getPrice();
    }
    else if (selectedDrink == LATTEMACCHIOTO)
    {
        LatteMacchiato drink;
        sugarAmount = drink.getSugarAmount();
        milkAmount = drink.getMilkAmount();
        hotWaterAmount = drink.getHotWaterAmount();
        recipeTemperature = drink.getRecipeTemperature();
        specificRecipeComponent = drink.getRecipeIngredient();
        price = drink.getPrice();
    }
    else if (selectedDrink == CACAO)
    {
        Cacao drink;
        sugarAmount = drink.getSugarAmount();
        milkAmount = drink.getMilkAmount();
        hotWaterAmount = drink.getHotWaterAmount();
        recipeTemperature = drink.getRecipeTemperature();
        specificRecipeComponent = drink.getRecipeIngredient();
        price = drink.getPrice();
    }
    else if (selectedDrink == HOTWATER)
    {
        HotWater drink;
        sugarAmount = drink.getSugarAmount();
        milkAmount = drink.getMilkAmount();
        hotWaterAmount = drink.getHotWaterAmount();
        recipeTemperature = drink.getRecipeTemperature();
        specificRecipeComponent = drink.getRecipeIngredient();
        price = drink.getPrice();
    }
    else if (selectedDrink == NO_DRINK)
    {
        sugarAmount = 0;
        milkAmount = 0;
        hotWaterAmount = 100;
        recipeTemperature = 0;
        specificRecipeComponent = 0;
        price = 0.0;
    }
    else
    {
        sugarAmount = 0;
        milkAmount = 0;
        hotWaterAmount = 0;
        recipeTemperature = 0;
        specificRecipeComponent = 0;
        price = 0.0;
    }



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


void UserChoice::setSugarAmount(int sugarAmount)
{
    this->sugarAmount = sugarAmount;
}

int UserChoice::getSugarAmount()
{
    return sugarAmount;
}

void UserChoice::setMilkAmount(int milkAmount)
{
    this->milkAmount = milkAmount;
}

int UserChoice::getMilkAmount()
{
    return milkAmount;
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
