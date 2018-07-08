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
        DrinkType getSelectedDrink() const;
        void setCard(Card *card);
        Card *getCard() const;
        void setSugarAmount(int sugarAmount);
        int getSugarAmount() const;
        void setMilkAmount(int milkAmount);
        int getMilkAmount() const;
        void setEnabledBigPortion();
        void setDisabledBigPortion();
        bool getBigPortion() const;
        void setDefaultChoice();
        double getPrice() const;
        int getHotWaterAmount() const;
        int getRecipeTemperature() const;
        int getSpecificRecipeComponent() const;
        QString printSelectedDrink();
};

extern UserChoice *activeUserChoice;

#endif // USERCHOICE_H
