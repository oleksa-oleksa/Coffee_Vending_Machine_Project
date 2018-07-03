#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"
#include "card.h"
#include "account.h"
#include "person.h"
#include "bankaccount.h"

class Admin : public Person
{
    public:
         Admin();
         Admin(Person *activeAdminPerson);
        ~Admin();  

         Person *instantiateNewPerson(Person *newPerson);
         BankAccount *instantiateNewBankAccount(BankAccount *newBankAccount);
         Account *instantiateNewAccount(Account *newAccount);
         Card *instantiateNewCard(Card *newCard);

         void cancelPersonCreation(Person *newPerson);
         void cancelBankAccountCreation(BankAccount *newBankAccount);
         void cancelAccountCreation(Account *newAccount);
         void cancelCardCreation(Card *newCard);

         bool hireEmployee();

};

extern Person *activeAdminPerson;
extern Person *newPerson;
extern BankAccount *newBankAccount;
extern Account *newAccount;
extern Card *newCard;

#endif // ADMIN_H
