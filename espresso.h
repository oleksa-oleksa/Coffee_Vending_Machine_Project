// Create by Oleksandra Baga
#ifndef ESPRESSO_H
#define ESPRESSO_H

#include "drink.h"
#include "ingredient.h"

class Espresso : public Drink
{
    private:
        int coffeePowderAmount;

    public:
        // COFFEE DEFAULT CONSTRUCTOR
        // RECIPE CANNOT BE SET, ONLY GET
        Espresso()
        {
            sugarAmount = 0;
            milkAmount = 0;
            hotWaterAmount = 100;
            recipeTemperature = 100;
            price = 0.7;
            coffeePowderAmount = 15;
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
