#ifndef CARD_H
#define CARD_H

#include "account.h"
#include "cardid.h"

class Account;

class Card
{
    private:
        CardID cardID;
        Account *account;

    public:
        Card();
        ~Card();
        CardID getCardID();
        void setAccount(Account *account);
        void setCardID(CardID newCardID);
        bool withdraw(double price);
};

#endif // CARD_H
