#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>

class BankAccount
{
    private:
        std::string IBAN;
        int taxClass;
    public:
        BankAccount();
        ~BankAccount();
        void setIBAN(std::string iban);
        std::string getIBAN();
        void setTaxClass(int tc);
        int getTaxClass();
};

#endif // BANKACCOUNT_H
