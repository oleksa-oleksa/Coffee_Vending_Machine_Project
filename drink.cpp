#include "drink.h"


Drink::Drink()
{

}


Drink::Drink(int sugarAmount,
             int milkAmount,
             int hotWaterAmount,
             int recipeTemperature,
             double price) {
    this->sugarAmount = sugarAmount;
    this->milkAmount = milkAmount;
    this->hotWaterAmount = hotWaterAmount;
    this->recipeTemperature = recipeTemperature;
    this->price = price;
}

int Drink::getSugarAmount() const {
    return sugarAmount;
}

int Drink::getMilkAmount() const {
    return milkAmount;
}

double Drink::getPrice() const {
    return price;
}

