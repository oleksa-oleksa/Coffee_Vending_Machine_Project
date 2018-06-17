#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "card.h"
#include "person.h"
#include "accountstatus.h"
#include "accountid.h"
#include "bankaccount.h"

class BankAccount;

class Account
{
    private:
        AccountID accountID;
        double credit;
        AccountStatus state;
        Person *owner;
        BankAccount *ba;

    public:
        Account(Person *newEmployee, BankAccount *newBa);
        AccountStatus getAccountStatus();
        void setAccountStatus(AccountStatus newState);
        bool checkCreditLimit();
        double getAccountCredit();
        void setAccountCredit(double amount);
        Person *getOwner();
        void setOwner(Person *owner);
        BankAccount *getBankAccount();
        void setBankAccount(BankAccount *ba);
        bool addCredit(double amount);
        void activateAccount();
        void deactivateAccount();
        void blockAccount();
};

#endif // ACCOUNT_H
