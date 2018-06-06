#include "card.h"
#include <iostream>
#include "accountstatus.h"
#include <QtDebug>

Card::Card()
{
    cardID = "0";
    account = new Account();
}

Card::~Card()
{
    if (account != NULL)
    {
        delete(account);
    }
}

std::string Card::getCardID()
{
    return cardID;
}

void Card::setCardID(std::string newCardID)
{
    cardID = newCardID;
    qDebug() << "Card ID is set";
}

bool Card::withdraw(double price)
{

    if (!account->addCredit(price))
    {
        qDebug() << "Error adding credit to card's account";
        return false;
    }

    return true;
}
