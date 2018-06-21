// Created by Oleksandra Baga
#include "card.h"
#include <iostream>
#include "accountstatus.h"
#include "cardstatus.h"
#include "cardid.h"
#include <QtDebug>

std::vector<Card>Card::AllCards = std::vector<Card>();

Card::Card(Account *ac)
{
    cardStatus = ACTIVE;
    account = ac;
}

Card::~Card()
{

}

// This constructor assumes that it receives a valid query
// pointing at some row of data from Card table
Card::Card(QSqlRecord &query)
{
    using namespace std;

    QString q_cid = query.value(0).toString();
    cardStatus = (CardStatus)query.value(1).toInt();
    QString q_aid = query.value(2).toString();

    cardID = CardID(q_cid.toUtf8().constData());
    AccountID accountID = AccountID(q_aid.toUtf8().constData());
    linkAccount(accountID);
}

CardID Card::getCardID()
{
    return cardID;
}

void Card::setCardID(CardID newCardID)
{
    cardID = newCardID;
    qDebug() << "Card ID is set";
}

CardStatus Card::getCardStatus()
{
    qDebug() << "Card status is: " << cardStatus;
    return cardStatus;

}

void Card::setCardStatus(CardStatus newStatus)
{
    cardStatus = newStatus;
    qDebug() << "Card status is set: " << cardStatus;
}

void Card::deactivateCard()
{
    qDebug() << "Card will be deactivated";
    setCardStatus(DEACTIVATED);
}

void Card::activateCard()
{
    qDebug() << "Card will be activated";
    setCardStatus(ACTIVE);
}

Account *Card::getAccount()
{

    qDebug() << "Account is: " << account->getAccountID().toQstring();
    return account;
}

void Card::setAccount(Account *newAccount)
{
    account = newAccount;
    qDebug() << "Account is set: " << account->getAccountID().toQstring();

}

bool Card::withdraw(double price)
{
   if (!account->getOwner()->getEmployed())
   {
       qDebug() << "Person is not a employee, payment is denied!";
       account->deactivateAccount();
       return false;
   }

   if (account->addCredit(price))
   {
       qDebug() << "Credit added to card's account";
       return true;
   }
   else
   {
       qDebug() << "Error adding credit to card's account";
       return false;
   }
}

bool Card::linkAccount(AccountID accountID)
{
    bool ret = false;

    for (size_t i = 0; i < Account::AllAccounts.size(); i++)
    {
       if (Account::AllAccounts[i].getAccountID().toQstring() == accountID.toQstring())
       {
          setAccount(&Account::AllAccounts[i]);
          qDebug() << "Account is set to AccountID:" << Account::AllAccounts[i].getAccountID().toQstring();
          ret = true;
       }
    }
    return ret;
}
