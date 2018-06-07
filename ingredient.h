#ifndef INGREDIENT_H
#define INGREDIENT_H

class Ingredient
{
   private:
      int sugar_amount           = 0;
      int milk_amount            = 0;
      int coffee_powder_amount   = 0;
      int cacao_powder_amount    = 0;
   public:
      Ingredient modifyIngredient(Ingredient thisingredient);
      void set_sugar(int sugar);
      void set_milk(int milk);
      void set_coffeePowder(int coffeePowder);
      void set_cacaoPowder(int cacaoPowder);
};

#endif
