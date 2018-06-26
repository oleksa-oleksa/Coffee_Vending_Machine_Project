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
        ~Admin();  
//        Person::AllEmployee addEmployee();
//        Person::AllEmployee deleteEmployee(Person person);
//        Person::AllEmployee editEmployee(Person person);
//        BankAccount::AllBankAccounts addBankAccountToProfil(AccountID accID);
//        BankAccount::AllBankAccounts editBankAccountInProfil(BankAccountID iban);
//        Account::AllAccounts addAccountToProfil(AccountID accID);
//        Account::AllAccounts editAccountInProfil(AccountID accID);
//        Card::AllCards addCardToProfil(AccountID accID);
//        Card::AllCards editCardInProfil(AccountID accID);



};

#endif // ADMIN_H
