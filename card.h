#ifndef CARD_H
#define CARD_H

#include "account.h"

class Card
{
    private:
        long cardID;
        Account *account;

    public:
        Card();
        long getCardID();
        void setCardID(Card card);
        bool withdraw(double price);
};

#endif // CARD_H
