#include "admin.h"
#include "card.h"

Admin::Admin()
{

}

Card * Admin::createCard()
{
    Card *newRandomCard = new Card();
    return newRandomCard;
}

void Admin::deactivateCard(Card c)
{

}

void Admin::createBill()
{

}

Account * Admin:: createAccount(Person *newEmployee)
{
    Account *newAccount = new Account(newEmployee);
    return newAccount;
}

void Admin::addCard(Account *account, Card *card)
{
    card->setAccount(account);
}


