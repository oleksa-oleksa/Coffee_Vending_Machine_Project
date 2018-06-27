// Create by Oleksandra Baga
#ifndef CAPPUCCINO_H
#define CAPPUCCINO_H

#include "drink.h"
#include "ingredient.h"

class Cappuccino : public Drink
{
    private:
        int coffeePowderAmount;

    public:
        // CAPPUCCINO DEFAULT CONSTRUCTOR
        // RECIPE CANNOT BE SET, ONLY GET
        Cappuccino()
        {
            sugarAmount = 3;
            milkAmount = 5;
            hotWaterAmount = 220;
            recipeTemperature = 100;
            price = 1.00;
            coffeePowderAmount = 7;
        }

        int getSugarAmount();
        int getMilkAmount();
        int getHotWaterAmount();
        int getRecipeTemperature();
        double getPrice();

        // the specific recipe ingredient. coffeePowderAmount for Coffee drink
        int getRecipeIngredient();

};

#endif
