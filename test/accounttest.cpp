#include "accounttest.h"

void AccountTest::testCheckCreditLimit()
{
    // The Credit limit for calculations is const CREDIT_LIMIT
    Account test01;

    test01.addCredit(8.0);
    QVERIFY(test01.checkCreditLimit());

    test01.addCredit(3.0);
    QVERIFY(test01.checkCreditLimit());

}
