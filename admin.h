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
        Card *createCard(Account *account);
        void deleteCard(Card *c);
        Account *createAccount(Person *Employee, BankAccount *Ba);
        void deleteAccount(Account *account);

};

#endif // ADMIN_H
