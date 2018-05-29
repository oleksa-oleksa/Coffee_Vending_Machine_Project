#include "card.h"
#include "accountstatus.h"
#include <QtDebug>

Card::Card()
{

}

long Card::getCardID()
{

}

void Card::setCardID(Card card)
{

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
