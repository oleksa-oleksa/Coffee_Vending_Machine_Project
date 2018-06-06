#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "card.h"
#include "person.h"
#include "accountstatus.h"
#include "bankaccount.h"

class Account
{
    private:
        double credit;
        AccountStatus state;
        Person *owner;
        BankAccount *ba;

    public:
        Account(Person *newEmployee, BankAccount *newBa);
        void setAccountStatus(AccountStatus newState);
        AccountStatus getAccountStatus();
        bool checkCreditLimit();
        double getAccountCredit();
        void setAccountCredit(double amount);
        bool addCredit(double amount);
        void activateAccount();
        void deactivateAccount();
        void blockAccount();
};

#endif // ACCOUNT_H
