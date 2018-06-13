#include "card.h"
#include <iostream>
#include "accountstatus.h"
#include "cardstatus.h"
#include "cardid.h"
#include <QtDebug>

Card::Card(Account *ac)
{
    cardStatus = ACTIVE;
    account = ac;
}

Card::~Card()
{

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
    qDebug() << "Card will be deactivated";
    setCardStatus(DEACTIVATED);
}

Account *Card::getAccount()
{
    return account;
}

void Card::setAccount(Account *newAccount)
{
    account = newAccount;
}


bool Card::withdraw(double price)
{
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
