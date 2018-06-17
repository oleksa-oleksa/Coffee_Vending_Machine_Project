#include "bankaccountid.h"
#include "tools.h"
#define IBAN_LEN 20 // will create 22 symbols


BankAccountID::BankAccountID()
{
    IBAN = std::string("DE") + createRandomID(IBAN_LEN);
}
