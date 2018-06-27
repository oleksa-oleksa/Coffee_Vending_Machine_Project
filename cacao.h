#ifndef CACAO_H
#define CACAO_H

#include "drink.h"
#include "ingredient.h"

class Cacao : public Drink
{
    private:
        int cacaoPowderAmount;

    public:
        // CACAO DEFAULT CONSTRUCTOR
        // RECIPE CANNOT BE SET, ONLY GET
        Coffee()
        {
            sugarAmount = 4;
            milkAmount = 4;
            hotWaterAmount = 220;
            recipeTemperature = 90;
            price = 1.20;
            cacaoPowderAmount = 20;
        }

        int getSugarAmount();
        int getMilkAmount();
        double getPrice();

        // the specific recipe ingredient. CacaoPowder for Cacao drink
        int getRecipeIngredient();

};

#endif
