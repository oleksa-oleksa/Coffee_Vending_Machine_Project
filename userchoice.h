#ifndef USERCHOICE_H
#define USERCHOICE_H

#include "card.h"
#include "drinktype.h"
#include "button.h"

class UserChoice
{
    private:
        DrinkType selectedDrink;
        Card *card;
        int sugarAmount;
        int milkAmount;
        bool isBigPortion;
        int hotWaterAmount;
        int recipeTemperature;
        int specificRecipeComponent;
        double price;

    public:
        UserChoice();
        UserChoice(Card *card);
        bool payDrink();
        void setSelectedDrink(DrinkType selectedDrink);
        DrinkType getSelectedDrink();
        void setCard(Card *card);
        Card *getCard();
        void setSugarAmount(int sugarAmount);
        int getSugarAmount();
        void setMilkAmount(int milkAmount);
        int getMilkAmount();
        void toggleBigPortion(); // setter
        bool getBigPortion();
        void setDefaultChoice();
        QString printSelectedDrink();
};

#endif // USERCHOICE_H
