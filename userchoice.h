#ifndef USERCHOICE_H
#define USERCHOICE_H

#include "card.h"
#include "DrinkType.h"

class UserChoice
{
    private:
        DrinkType *selectedDrink;
        Card card;
        int extraSugar;
        int extraMilk;
        double price;

    public:
        UserChoice();
        ~UserChoice();
        bool payDrink(double price);
        DrinkType getProgramButtonState();
        int getSugarButtonState();
        int getMilkButtonState();
        bool getOKButtonState();
        DrinkType setSelectedDrink(DrinkType drink);
};

#endif // USERCHOICE_H
