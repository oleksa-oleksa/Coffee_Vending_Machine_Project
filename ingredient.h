// Exisiting file implemented for project by Oleksandra Baga
#ifndef INGREDIENT_H
#define INGREDIENT_H

#define SUGAR_TANK_AMOUNT 50
#define MILK_TANK_AMOUNT 50
#define COFFEE_TANK_AMOUNT 100
#define CACAO_TANK_AMOUNT 30

class Ingredient
{
   private:
      int sugarIngredient;
      int milkIngredient;
      int coffeeIngredient;
      int cacaoIngredient;

   public:
      Ingredient();
      Ingredient(int sugarIngredient, int milkIngredient, int coffeeIngredient, int cacaoIngredient);

      void refillAllIngredients();
      void refillSugarTank();
      void refillMilkTank();
      void refillCoffeeTank();
      void refillCacaoTank();

      void setSugarIngredient(int sugarIngredient);
      void setMilkIngredient(int milkIngredient);
      void setCoffeeIngredient(int coffeeIngredient);
      void setCacaoIngredient(int cacaoIngredient);

      int getSugarIngredient() const;
      int getMilkIngredient() const;
      int getCoffeeIngredient() const;
      int getCacaoIngredient() const;
};

#endif
