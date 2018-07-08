// Create by Oleksandra Baga
#include "drink.h"
#include "hotwater.h"

int HotWater::getSugarAmount() const {
    return sugarAmount;
}

int HotWater::getMilkAmount() const {
    return milkAmount;
}

int HotWater::getHotWaterAmount() const {
    return hotWaterAmount;
}
int HotWater::getRecipeTemperature() const {
    return recipeTemperature;
}

double HotWater::getPrice() const {
    return price;
}

int HotWater::getRecipeIngredient() const {
    return specificIngredient;
}
