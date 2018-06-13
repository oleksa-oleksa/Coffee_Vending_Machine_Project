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
        int extraSugar;
        int extraMilk;
        bool isBigPortion;
        double price;

    public:
        UserChoice();
        bool payDrink();
        DrinkType setSelectedDrink(DrinkType drink);
        void setExtraSugar(int sugar);
        void setMilkQuantity(int milkQuantity);
        void toggleBigPortion();
        double setPrice();
};

#endif // USERCHOICE_H
