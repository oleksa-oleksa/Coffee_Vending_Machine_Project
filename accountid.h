#ifndef ACCOUNTID_H
#define ACCOUNTID_H
#include <iostream>
#include <QString>

#define ACCOUNT_ID_LEN 8

class AccountID
{
    private:
        std::string accountID;
    public:
        AccountID(std::string id);
        AccountID();
        QString toQstring();
};

#endif // ACCOUNTID_H
