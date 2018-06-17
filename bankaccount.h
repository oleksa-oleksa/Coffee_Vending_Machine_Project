#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include "account.h"
#include "bankaccountid.h"

class Account;

class BankAccount
{
    private:
        BankAccountID IBAN;
        int taxClass;
        Account *account; // create account before card and ba instances
    public:
        BankAccount();
        ~BankAccount();
        void setAccount(Account *account);
        Account *getAccount();
        void setIBAN(BankAccountID iban);
        BankAccountID getIBAN();
        void setTaxClass(int tc);
        int getTaxClass();
};

#endif // BANKACCOUNT_H
