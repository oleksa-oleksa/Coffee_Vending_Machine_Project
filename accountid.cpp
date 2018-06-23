// Created by Oleksandra Baga
#include "accountid.h"
#include "tools.h"
#include <iostream>

AccountID::AccountID(std::string id) : accountID(id)
{

}

AccountID::AccountID()
{
    accountID = std::string("ACC") + createRandomID(ACCOUNT_ID_LEN);
}

QString AccountID::toQstring()
{
  return QString::fromUtf8(accountID.c_str());
}


