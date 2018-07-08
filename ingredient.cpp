// Exisiting file implemented for project by Oleksandra Baga
#include "ingredient.h"

Ingredient::Ingredient() {
    sugarIngredient = SUGAR_TANK_AMOUNT;
    milkIngredient = MILK_TANK_AMOUNT;
    coffeeIngredient = COFFEE_TANK_AMOUNT;
    cacaoIngredient = CACAO_TANK_AMOUNT;

}
Ingredient::Ingredient(int sugarIngredient, int milkIngredient, int coffeeIngredient, int cacaoIngredient) {
    this->sugarIngredient = sugarIngredient;
    this->milkIngredient = milkIngredient;
    this->coffeeIngredient = coffeeIngredient;
    this->cacaoIngredient = cacaoIngredient;
}

void Ingredient::refillAllIngredients() {
    sugarIngredient = SUGAR_TANK_AMOUNT;
    milkIngredient = MILK_TANK_AMOUNT;
    coffeeIngredient = COFFEE_TANK_AMOUNT;
    cacaoIngredient = CACAO_TANK_AMOUNT;
}

void Ingredient::refillSugarTank() {
    sugarIngredient = SUGAR_TANK_AMOUNT;
}

void Ingredient::refillMilkTank() {
    milkIngredient = MILK_TANK_AMOUNT;
}

void Ingredient::refillCoffeeTank() {
    coffeeIngredient = COFFEE_TANK_AMOUNT;
}

void Ingredient::refillCacaoTank() {
    cacaoIngredient = CACAO_TANK_AMOUNT;
}

void Ingredient::setSugarIngredient(int sugarIngredient) {
    this->sugarIngredient = sugarIngredient;
}
void Ingredient::setMilkIngredient(int milkIngredient) {
    this->milkIngredient = milkIngredient;
}
void Ingredient::setCoffeeIngredient(int coffeeIngredient) {
    this->coffeeIngredient = coffeeIngredient;
}

void Ingredient::setCacaoIngredient(int cacaoIngredient) {
    this->cacaoIngredient = cacaoIngredient;
}

int Ingredient::getSugarIngredient() const {
    return sugarIngredient;
}

int Ingredient::getMilkIngredient() const {
    return milkIngredient;
}

int Ingredient::getCoffeeIngredient() const {
    return coffeeIngredient;
}
int Ingredient::getCacaoIngredient() const {
    return cacaoIngredient;
}
