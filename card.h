#ifndef CARD_H
#define CARD_H

#include "account.h"
#include "cardid.h"
#include "cardstatus.h"

class Account;

class Card
{
    private:
        CardID cardID;
        CardStatus cardStatus;
        Account *account;

    public:
        Card(Account *ac);
        ~Card();
        static std::vector<Card> AllCards;

        CardID getCardID();
        void setCardID(CardID newCardID);
        CardStatus getCardStatus();
        void setCardStatus(CardStatus newStatus);
        void deactivateCard();
        void activateCard();
        Account *getAccount();
        void setAccount(Account *account);
        bool withdraw(double price);
};

typedef std::vector<Card> Cards;

#endif // CARD_H
