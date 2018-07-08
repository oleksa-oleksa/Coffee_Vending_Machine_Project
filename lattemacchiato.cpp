// Create by Oleksandra Baga
#include "drink.h"
#include "lattemacchiato.h"

int LatteMacchiato::getSugarAmount() const {
    return sugarAmount;
}

int LatteMacchiato::getMilkAmount() const {
    return milkAmount;
}

int LatteMacchiato::getHotWaterAmount() const {
    return hotWaterAmount;
}
int LatteMacchiato::getRecipeTemperature() const {
    return recipeTemperature;
}

double LatteMacchiato::getPrice() const {
    return price;
}

int LatteMacchiato::getRecipeIngredient() const {
    return coffeePowderAmount;
}
