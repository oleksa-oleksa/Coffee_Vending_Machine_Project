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
        UserChoice(Card *card);
        bool payDrink();
        void setSelectedDrink(DrinkType selectedDrink);
        DrinkType getSelectedDrink();
        void setCard(Card *card);
        Card *getCard();
        void setExtraSugar(int extraSugar);
        int getExtraSugar();
        void setExtraMilk(int extraMilk);
        int getExtraMilk();
        void toggleBigPortion(); // setter
        bool getBigPortion();
        double getPrice(); // price is predefined, no setter needed
        void setDefaultChoice();
        QString printSelectedDrink();
};

#endif // USERCHOICE_H
