// Created by Oleksandra Baga
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "card.h"
#include "person.h"
#include "accountstatus.h"
#include "accountid.h"
#include "bankaccount.h"
#include "bankaccountid.h"
#include <QSqlRecord>
#include <string>

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
        static std::vector<Account> AllAccounts;

        AccountStatus getAccountStatus();
        void setAccountStatus(AccountStatus newState);
        bool checkCreditLimit(double amount);
        double getAccountCredit();
        void setAccountCredit(double credit); // Simple setter
        bool addCredit(double amount); // increases credit
        Person *getOwner();
        void setOwner(Person *owner);
        BankAccount *getBankAccount();
        void setBankAccount(BankAccount *ba);
        void setAccountID(AccountID accountID);
        AccountID getAccountID();
        void activateAccount();
        void deactivateAccount();
        void blockAccount();
        bool linkOwner(PersonID personID);
        bool linkBankAccount(BankAccountID iban);
        QString printAccountStatus();
};

typedef std::vector<Account> Accounts;

#endif // ACCOUNT_H
