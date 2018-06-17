#include "bankaccountid.h"
#include "tools.h"
#define BA_ID_LEN 8


BankAccountID::BankAccountID()
{
    bankAccountID = createRandomID(BA_ID_LEN);
}
