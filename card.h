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
        void setAccount(Account *account);
        Account *getAccount();
        CardID getCardID();
        void setCardID(CardID newCardID);
        bool withdraw(double price);
};

#endif // CARD_H
