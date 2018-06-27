// Create by Oleksandra Baga
#ifndef HOTWATER_H
#define HOTWATER_H

#include "drink.h"

//
#include "ingredient.h"

class HotWater : public Drink
{
    private:
        int specificIngredient;

    public:
        // HOTWATER DEFAULT CONSTRUCTOR
        // RECIPE CANNOT BE SET, ONLY GET
        HotWater()
        {
            sugarAmount = 0;
            milkAmount = 0;
            hotWaterAmount = 200;
            recipeTemperature = 100;
            price = 0.1;
            specificIngredient = 0;
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
