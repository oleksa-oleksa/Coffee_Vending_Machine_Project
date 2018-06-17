#include "accountid.h"
#include "tools.h"

AccountID::AccountID()
{
    accountID = createRandomID(ACCOUNT_ID_LEN);
}


