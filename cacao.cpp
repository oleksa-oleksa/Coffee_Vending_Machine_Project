// Create by Oleksandra Baga
#include "drink.h"
#include "cacao.h"

int Cacao::getSugarAmount() const {
    return sugarAmount;
}

int Cacao::getMilkAmount() const {
    return milkAmount;
}

int Cacao::getHotWaterAmount() const {
    return hotWaterAmount;
}
int Cacao::getRecipeTemperature() const {
    return recipeTemperature;
}

double Cacao::getPrice() const {
    return price;
}

int Cacao::getRecipeIngredient() const {
    return cacaoPowderAmount;
}
