#ifndef CARD_H
#define CARD_H

#include "account.h"
#include <iostream>

class Account;

class Card
{
    private:
        std::string cardID;
        Account *account;

    public:
        Card();
        ~Card();
        std::string getCardID();
        void setCardID(std::string newCardID);
        bool withdraw(double price);
};

#endif // CARD_H
