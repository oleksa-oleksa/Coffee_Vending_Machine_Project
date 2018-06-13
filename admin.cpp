#include "admin.h"
#include "card.h"
#include "account.h"
#include "cardstatus.h"

Admin::Admin()
{

}

// creates new active card with random id
Card *Admin::createCard(Account *account)
{
    Card *newRandomCard = new Card(Account *account);
    return newRandomCard;
}

void deleteCard(Card *c)
{
    delete c;
}

Account * Admin:: createAccount(Person *newEmployee)
{
    Account *newAccount = new Account(newEmployee);
    return newAccount;
}
