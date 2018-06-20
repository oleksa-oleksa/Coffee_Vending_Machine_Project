#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "card.h"
#include "person.h"
#include "accountstatus.h"
#include "accountid.h"
#include "bankaccount.h"

// The Accounts are saved in std::vector Accounts


class BankAccount;

class Account
{
    friend class Database;
    private:
        Person *owner;
        BankAccount *ba;
        AccountID accountID;
        double credit;
        AccountStatus state;

        // Constructor to be used by database class
        Account(QSqlRecord &query);

    public:
        Account();

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

typedef std::vector<Account> Accounts;

#endif // ACCOUNT_H
