// Create by Oleksandra Baga
#include "drink.h"
#include "espresso.h"

int Espresso::getSugarAmount() const {
    return sugarAmount;
}

int Espresso::getMilkAmount() const {
    return milkAmount;
}

int Espresso::getHotWaterAmount() const {
    return hotWaterAmount;
}
int Espresso::getRecipeTemperature() const {
    return recipeTemperature;
}

double Espresso::getPrice() const {
    return price;
}

int Espresso::getRecipeIngredient() const {
    return coffeePowderAmount;
}
