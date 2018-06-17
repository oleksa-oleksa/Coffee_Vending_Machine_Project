#include "bankaccountid.h"
#include "tools.h"

BankAccountID::BankAccountID()
{
    IBAN = std::string("DE") + createRandomID(IBAN_LEN);
}
