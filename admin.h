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

         void cancelPersonCreation(Person *newPerson);
         void cancelBankAccountCreation(BankAccount *newBankAccount);
         void cancelAccountCreation(Account *newAccount);
         void cancelCardCreation(Card *newCard);

         void addPerson(Person *newPerson, std::string newPersonName, std::string newPersonSurname,
                        std::string newPersonAddress, int isAdmin, int isStaff);
         void addBankAccount(BankAccount *newBankAccount, int taxClass);
         void addAccount(Account *newAccount);
         void addCard(Card *newCard);

};

extern Person *activeAdminPerson;
extern Person *newPerson;
extern BankAccount *newBankAccount;
extern Account *newAccount;
extern Card *newCard;

#endif // ADMIN_H
