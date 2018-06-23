#include "accounttest.h"


void AccountTest::testCheckCreditLimit()
{
    // The Credit limit for calculations is const CREDIT_LIMIT
    Account test01;

    // PASS: credit os 0.0 after object creation.
    test01.addCredit(8.0);
    //QCOMPARE(test01.checkCreditLimit(), true);

    // PASS. credit is 8.0 after first purchase
    test01.addCredit(3.0);
    //QCOMPARE(test01.checkCreditLimit(), true);

    // FAIL. credit is 11.0 after first purchase
    test01.addCredit(1.0);
    //QCOMPARE(test01.checkCreditLimit(), false);

}


//void AccountTest::testAddCredit()
//{
//    Account test01;
//    test01.setAccountCredit(10);
//    QCOMPARE(test01.addCredit(2), 12);
//}

