// Create by Oleksandra Baga
#include "drink.h"
#include "cappuccino.h"

int Cappuccino::getSugarAmount() const {
    return sugarAmount;
}

int Cappuccino::getMilkAmount() const {
    return milkAmount;
}

int Cappuccino::getHotWaterAmount() const {
    return hotWaterAmount;
}

int Cappuccino::getRecipeTemperature() const {
    return recipeTemperature;
}

double Cappuccino::getPrice() const {
    return price;
}

int Cappuccino::getRecipeIngredient() const {
    return coffeePowderAmount;
}
