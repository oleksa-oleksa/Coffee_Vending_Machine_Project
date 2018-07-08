// Created by Oleksandra Baga
#ifndef CARD_H
#define CARD_H

#include "account.h"
#include "cardid.h"
#include "cardstatus.h"
#include "accountid.h"
#include <QSqlRecord>

class Account;

class Card
{
    friend class Database;
    private:
        CardID cardID;
        CardStatus cardStatus;
        Account *account;

        // Constructor to be used by database class
        Card(QSqlRecord &query);

    public:
        Card();
        Card(Account *ac);
        ~Card();
        static std::vector<Card> AllCards;

        CardID getCardID() const;
        void setCardID(CardID newCardID);
        CardStatus getCardStatus();
        void setCardStatus(CardStatus newStatus);
        void deactivateCard();
        void activateCard();
        Account *getAccount() const;
        void setAccount(Account *account);
        bool withdraw(double price);
        bool linkAccount(AccountID accountID);
        QString printCardStatus();
};

typedef std::vector<Card> Cards;

extern Card *card;

#endif // CARD_H
