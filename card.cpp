#include "card.h"
#include <iostream>
#include "accountstatus.h"
#include "cardid.h"
#include <QtDebug>

Card::Card()
{

}

Card::~Card()
{

}

CardID Card::getCardID()
{
    return cardID;
}

void Card::setAccount(Account *newAccount)
{
    account = newAccount;
}

Account *Card::getAccount()
{
    return account;
}

void Card::setCardID(CardID newCardID)
{
    cardID = newCardID;
    qDebug() << "Card ID is set";
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
