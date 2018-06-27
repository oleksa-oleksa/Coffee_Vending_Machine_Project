// Create by Oleksandra Baga
#ifndef LATTEMACCHIATO_H
#define LATTEMACCHIATO_H

#include "drink.h"
#include "ingredient.h"

class LatteMacchiato : public Drink
{
    private:
        int coffeePowderAmount;

    public:
        // LATTEMACCHIATO DEFAULT CONSTRUCTOR
        // RECIPE CANNOT BE SET, ONLY GET
        Coffee()
        {
            sugarAmount = 2;
            milkAmount = 5;
            hotWaterAmount = 250;
            recipeTemperature = 90;
            price = 1.4;
            coffeePowderAmount = 7;
        }

        int getSugarAmount();
        int getMilkAmount();
        double getPrice();

        // the specific recipe ingredient. coffeePowderAmount for Coffee drink
        int getRecipeIngredient();

};
