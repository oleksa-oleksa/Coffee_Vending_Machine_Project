#include "accountid.h"
#include "tools.h"
#define ACCOUNT_ID_LEN 10

AccountID::AccountID()
{
    accountID = createRandomID(ACCOUNT_ID_LEN);
}


