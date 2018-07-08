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
        Cacao()
        {
            sugarAmount = 2;
            milkAmount = 0;
            hotWaterAmount = 220;
            recipeTemperature = 90;
            price = 1.20;
            cacaoPowderAmount = 20;
        }

        int getSugarAmount() const;
        int getMilkAmount() const;
        int getHotWaterAmount() const;
        int getRecipeTemperature() const;
        double getPrice() const;

        // the specific recipe ingredient. CacaoPowder for Cacao drink
        int getRecipeIngredient() const;

};

#endif
