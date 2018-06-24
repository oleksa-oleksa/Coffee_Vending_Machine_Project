#include "drink.h"

//Drink::Drink(int sugar, int milk, int coffee,
//      int cacao, int water, int temp, double p)
//{
//    sugarAmount = sugar;
//    milkAmount = milk;
//    coffeePowderAmount = coffee;
//    cacaoPowderAmount = cacao;
//    hotWater = water;
//    recipeTemperature = temp;
//    price = p;
//}

Drink::Drink()
{

}


Drink::Drink(int sugarAmount,
             int milkAmount,
             int hotWaterAmount,
             int recipeTemperature,
             double price)
{
    this->sugarAmount = sugarAmount;
    this->milkAmount = milkAmount;
    this->hotWaterAmount = hotWaterAmount;
    this->recipeTemperature = recipeTemperature;
    this->price = price;
}

int Drink::getSugarAmount()
{
    return sugarAmount;
}

int Drink::getMilkAmount()
{
    return milkAmount;
}

double Drink::getPrice()
{
    return price;
}

//Drink DrinkRecipes[] = {
//    Drink(1, 1, 1, 0, 200, 100, 0.9), // COFFEE,
//    Drink(), // CAPPUCCINO,
//    Drink(), // ESPRESSO,
//    Drink(), // LATTEMACCHIOTO,
//    Drink(), // CACAO,
//    Drink()  // HOTWATER
//
//};
