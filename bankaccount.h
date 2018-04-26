#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "account.h"

class BankAccount
{
    private:
        String IBAN;
        int taxClass;
    public:
        BankAccount();
        ~BankAccount();
        void setIBAN(String iban);
        String getIBAN(BankAccount b);
        void setTaxClass(int tc);
        int getTaxClass(BankAccount b);
};

#endif // BANKACCOUNT_H
