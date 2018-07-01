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

#define BIG_PORTION_OVERPRICE 0.4
#define BIG_HOTWATER_OVERPRICE 0.1

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
        bool ret = card->withdraw(price);
        qDebug() << "payDrink() finished with exit code " << ret;
        return ret;
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
    if (selectedDrink == HOTWATER)
    {
        qDebug() << "No sugar for hot water";
        this->sugarAmount = 0;
        return;
    }

    if (sugarAmount >= 0 && sugarAmount < 5)
    {
        this->sugarAmount = sugarAmount;
        qDebug() << "Sugar is: " << this->sugarAmount;
        return;
    }
    else
    {
        qDebug() << "This is not allowed for sugar";
        return;
    }
}

int UserChoice::getSugarAmount()
{
    return sugarAmount;
}

void UserChoice::setMilkAmount(int milkAmount)
{
    // milk amount if these drinks can not be modified
    if (selectedDrink == CACAO  || selectedDrink == ESPRESSO || selectedDrink == HOTWATER)
    {
        qDebug() << "Predefined milk can not be changed";
        return;
    }

    if (milkAmount >= 0 && milkAmount < 5)
    {
        this->milkAmount = milkAmount;
        qDebug() << "Milk is: " << this->milkAmount;
        return;
    }    
    else
    {
        qDebug() << "This is not allowed for milk";
        return;
    }
}

int UserChoice::getMilkAmount()
{
    return milkAmount;
}


void UserChoice::setEnabledBigPortion()
{
    isBigPortion = true;
}

void UserChoice::setDisabledBigPortion()
{
    isBigPortion = false;
}

bool UserChoice::getBigPortion()
{
    return isBigPortion;
}

double UserChoice::getPrice()
{
    if (selectedDrink == NO_DRINK)
    {
        return 0.0;
    }

    if (isBigPortion && selectedDrink == HOTWATER)
    {
        return price + BIG_HOTWATER_OVERPRICE;
    }
    else if (isBigPortion )
    {
        return price + BIG_PORTION_OVERPRICE;
    }
    else
    {
        return price;
    }

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
    return "NO_DRINK";
}

int UserChoice::getHotWaterAmount()
{
    return hotWaterAmount;
}
int UserChoice::getRecipeTemperature()
{
    return recipeTemperature;
}
int UserChoice::getSpecificRecipeComponent()
{
    return specificRecipeComponent;
}
