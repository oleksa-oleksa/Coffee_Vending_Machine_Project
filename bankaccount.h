#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include "account.h"

class Account;

class BankAccount
{
    private:
        std::string IBAN;
        int taxClass;
        Account *account; // create account before card and ba instances
    public:
        BankAccount();
        ~BankAccount();
        void setAccount(Account *account);
        Account *getAccount();
        void setIBAN(std::string iban);
        std::string getIBAN();
        void setTaxClass(int tc);
        int getTaxClass();
};

#endif // BANKACCOUNT_H
