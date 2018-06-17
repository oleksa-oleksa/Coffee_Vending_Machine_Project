#ifndef BANKACCOUNTID_H
#define BANKACCOUNTID_H
#include <iostream>

#define IBAN_LEN 20 // will create 22 symbols

class BankAccountID
{
    private:
        std::string IBAN;

    public:
        BankAccountID();
};

#endif // BANKACCOUNTID_H
