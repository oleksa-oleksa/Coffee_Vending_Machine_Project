#ifndef USERCHOICE_H
#define USERCHOICE_H

#include "card.h"
#include "drinktype.h"
#include "button.h"

class UserChoice
{
    private:
        DrinkType selectedDrink;
        Card card;
        int extraSugar;
        int extraMilk;
        bool isBigPortion;
        double price;

    public:
        UserChoice();
        bool payDrink(double price);
        DrinkType getProgramButtonState();
        int getSugarButtonState();
        int getMilkButtonState();
        bool getOKButtonState();
        DrinkType setSelectedDrink(DrinkType drink);

        void setExtraSugar(int sugar);
        void setMilkQuantity(int milkQuantity);
        void setBigPortion(bool isBigPortion);
};

#endif // USERCHOICE_H
