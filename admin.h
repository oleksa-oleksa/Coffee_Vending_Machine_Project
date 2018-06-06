#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"
#include "card.h"
#include "account.h"

class Admin : public Person
{
    public:
         Admin();
        ~Admin();
        Card * createCard();
        void deactivateCard(Card c);
        void createBill();
        Account * createAccount(Person *newEmployee);
        void addCard(Account *account, Card *card);
};

#endif // ADMIN_H
