// Created by Oleksandra Baga
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include "account.h"
#include "bankaccountid.h"
#include <QSqlRecord>
#include <qsqlrecord.h>


// The Bank Accounts are saved in std::vector bankAccounts

class Account;

class BankAccount
{
    friend class Database;
    private:
        BankAccountID IBAN;
        AccountID accountID;
        Account *account; // account id will be created with BA at the same time
                          // and then assigned to the account
                         // this is the solution for this particular issue
        int taxClass;

        // Constructor to be used by database class
        BankAccount(QSqlRecord &query);

    public:
        BankAccount();
        static std::vector<BankAccount> AllBankAccounts;

        void setIBAN(BankAccountID iban);
        BankAccountID getIBAN() const;
        void setAccountID(AccountID accountID);
        AccountID getAccountID() const;
        void setAccount(Account *account);
        Account *getAccount() const;
        void setTaxClass(int tc);
        int getTaxClass() const;
        bool linkAccount();
        bool linkProvidedAccount(AccountID accountID);
};

typedef std::vector<BankAccount> BAccounts;
extern BankAccount *bankAccount;

#endif // BANKACCOUNT_H
