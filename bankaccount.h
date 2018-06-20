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
        void setIBAN(BankAccountID iban);
        BankAccountID getIBAN();
        void setAccountID(AccountID accountID);
        AccountID getAccountID();
        void setAccount(Account *account);
        Account *getAccount();
        void setTaxClass(int tc);
        int getTaxClass();
};

typedef std::vector<BankAccount> BAccounts;


#endif // BANKACCOUNT_H
