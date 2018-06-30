#ifndef USERCHOICE_H
#define USERCHOICE_H

#include "card.h"
#include "drinktype.h"
#include "button.h"

class UserChoice
{
    private:
        Card *card;
        DrinkType selectedDrink;
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
        void setEnabledBigPortion();
        void setDisabledBigPortion();
        bool getBigPortion();
        void setDefaultChoice();
        double getPrice();
        QString printSelectedDrink();
};

#endif // USERCHOICE_H
