#include "accountid.h"
#include "tools.h"
#define ACCOUNT_ID_LEN 12

AccountID::AccountID()
{
    accountID = createRandomID(ACCOUNT_ID_LEN);
}


