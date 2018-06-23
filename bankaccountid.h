// Created by Oleksandra Baga
#ifndef BANKACCOUNTID_H
#define BANKACCOUNTID_H
#include <iostream>
#include <QString>

#define IBAN_LEN 16 // will create 22 symbols for IBAN starting with DEBBER

class BankAccountID
{
    private:
        std::string IBAN;

    public:
        BankAccountID(std::string id);
        BankAccountID();
        QString toQstring();

};

#endif // BANKACCOUNTID_H
