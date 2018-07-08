// Create by Oleksandra Baga
#include "drink.h"
#include "coffee.h"

int Coffee::getSugarAmount() const {
    return sugarAmount;
}

int Coffee::getMilkAmount() const {
    return milkAmount;
}

int Coffee::getHotWaterAmount() const {
    return hotWaterAmount;
}
int Coffee::getRecipeTemperature() const {
    return recipeTemperature;
}

double Coffee::getPrice() const {
    return price;
}

int Coffee::getRecipeIngredient() const {
    return coffeePowderAmount;
}
