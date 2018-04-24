#ifndef USERCHOICE_H
#define USERCHOICE_H

#include "card.h"
#include "drinktype.h"

class UserChoice
{
public:
    UserChoice();
    ~UserChoice();
    bool payDrink(double price);
    DrinkType getProgramButtonState();
    int getSugarButtonState();
    int getMilkButtonState();
    bool getOKButtonState();
    DrinkType setSelectedDrink(DrinkType drink);

private:
    DrinkType *selectedDrink;
    Card card;
    int extraSugar;
    int extraMilk;
    double price;
};

#endif // USERCHOICE_H
