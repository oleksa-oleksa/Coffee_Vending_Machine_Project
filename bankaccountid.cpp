#include "bankaccountid.h"
#include "tools.h"

BankAccountID::BankAccountID(std::string id) : IBAN(id)
{

}

BankAccountID::BankAccountID()
{
    IBAN = std::string("DEBBER") + createRandomID(IBAN_LEN);
}

QString BankAccountID::toQstring()
{
  return QString::fromUtf8(IBAN.c_str());
}
