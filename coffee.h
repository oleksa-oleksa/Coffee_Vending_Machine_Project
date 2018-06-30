// Create by Oleksandra Baga
#ifndef COFFEE_H
#define COFFEE_H

#include "drink.h"
#include "ingredient.h"

class Coffee : public Drink
{
    private:
        int coffeePowderAmount;

    public:
        // COFFEE DEFAULT CONSTRUCTOR
        // RECIPE CANNOT BE SET, ONLY GET
        Coffee()
        {
            sugarAmount = 2;
            milkAmount = 3;
            hotWaterAmount = 180;
            recipeTemperature = 100;
            price = 0.9;
            coffeePowderAmount = 10;
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
