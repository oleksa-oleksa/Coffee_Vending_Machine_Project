#ifndef USERCHOICE_H
#define USERCHOICE_H

#include "card.h"
#include "drinktype.h"
#include "button.h"

#define COMPONENT_MAXIMUM 5

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
        int getHotWaterAmount();
        int getRecipeTemperature();
        int getSpecificRecipeComponent();
        QString printSelectedDrink();
};

extern UserChoice *activeUserChoice;

#endif // USERCHOICE_H
