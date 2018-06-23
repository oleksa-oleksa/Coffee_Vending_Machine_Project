#include "accounttest.h"
#include "person.h"

void AccountTest::testCheckCreditLimit()
{
    // The Credit limit for calculations is const CREDIT_LIMIT
    Account test01;
    test01.setAccountCredit(8.0);

    // PASS 8.0 + 1.5 < 10.0
    qDebug() << "01:";
    QCOMPARE(test01.checkCreditLimit(1.5), true);

    // FAIL 8.0 + 3.0 > 10.0
    // Expected: 2€ is available
    qDebug() << "02:";
    QCOMPARE(test01.checkCreditLimit(3), false);

    // PASS, impossible negative preis => the credit will decreased
    qDebug() << "03:";
    QCOMPARE(test01.checkCreditLimit(-2), true);

    // FAIL. Expected: Account is blocked
    qDebug() << "04:";
    test01.setAccountCredit(12.0);
    QCOMPARE(test01.checkCreditLimit(0.35), false);

    // FAIL. Cannot buy with blocked account
    qDebug() << "05:";
    QCOMPARE(test01.checkCreditLimit(0.85), false);

    // FAIL. Expected: 0.80€ is available
    qDebug() << "06:";
    test01.setAccountStatus(ACTIVE_OK);
    test01.setAccountCredit(9.20);
    QCOMPARE(test01.checkCreditLimit(0.85), false);
}


void AccountTest::testAddCredit()
{
    Account test01;
    test01.setAccountCredit(8);

    // PASS 8.0 + 1.5 < 10.0
    qDebug() << "01:";
    QCOMPARE(test01.addCredit(1.5), true);
    test01.getAccountCredit();

    // FAIL 9.5 + 1.25 > 10.0
    qDebug() << "02:";
    QCOMPARE(test01.addCredit(1.25), false);
    test01.getAccountCredit();

    // PASS 9.5 + 0.25 < 10.0
    qDebug() << "03:";
    QCOMPARE(test01.addCredit(0.25), true);
    test01.getAccountCredit();
}

void AccountTest::testActivateAccount()
{
    Account test01;

    // PASS
    qDebug() << "01:";
    test01.getAccountStatus();
    test01.activateAccount();
    test01.getAccountStatus();

    // PASS
    qDebug() << "02:";
    test01.setAccountStatus(BLOCKED_UNPAID);
    test01.getAccountStatus();
    test01.activateAccount();
    test01.getAccountStatus();

    // PASS
    qDebug() << "03:";
    test01.setAccountStatus(DEACTIVATED_OLD);
    test01.getAccountStatus();
    test01.activateAccount();
    test01.getAccountStatus();

}


void AccountTest::testDeactivateAccount()
{
    Account test01;

    // PASS
    qDebug() << "01:";
    test01.getAccountStatus(); // ACTIVE after creation
    test01.deactivateAccount();
    test01.getAccountStatus();

    // PASS
    qDebug() << "02:";
    test01.setAccountStatus(ACTIVE_OK);
    test01.getAccountStatus();
    test01.deactivateAccount();
    test01.getAccountStatus();

    // PASS
    qDebug() << "03:";
    test01.setAccountStatus(BLOCKED_UNPAID);
    test01.getAccountStatus();
    test01.deactivateAccount();
    test01.getAccountStatus();

}

void AccountTest::testBlockAccount()
{
    Account test01;

    // PASS
    qDebug() << "01:";
    test01.getAccountStatus();
    test01.blockAccount();
    test01.getAccountStatus();

    // PASS
    qDebug() << "02:";
    test01.blockAccount();
    test01.getAccountStatus();

    // PASS
    qDebug() << "03:";
    test01.setAccountStatus(DEACTIVATED_OLD);
    test01.getAccountStatus();
    test01.blockAccount();
    test01.getAccountStatus();

}

void AccountTest::testLinkOwner()
{
    Person test01;
    Person test02;

    Person::AllEmployee.push_back(test01);
    Person::AllEmployee.push_back(test02);

    PersonID tmpID01 = test01.getID();
    PersonID tmpID02 = test02.getID();

    Account acc01;

    qDebug() << "VERIFY: New created account personID: " << acc01.getOwner();

    QVERIFY(acc01.linkOwner(tmpID01));
    qDebug() << "VERIFY: Linked account personID is: " << acc01.getOwner()->getID().toQstring();

    QVERIFY(acc01.linkOwner(tmpID02));
    qDebug() << "VERIFY: Linked account personID is: " << acc01.getOwner()->getID().toQstring();
}

void AccountTest::testLinkBankAccount()
{
    BankAccount test01;
    BankAccount::AllBankAccounts.push_back(test01);

    BankAccountID tmpID01 = test01.getIBAN();
    qDebug() << "GETTER: IBAN is: " << tmpID01.toQstring();

    BankAccountID tmpID02; // Random ID not existing in AllBankAccounts
    qDebug() << "GETTER: IBAN is: " << tmpID02.toQstring();

    Account acc01;

    qDebug() << "VERIFY: New created account IBAN: " << acc01.getBankAccount();

    // PASS, ID existing in Array
    QCOMPARE(acc01.linkBankAccount(tmpID01), true);

    // FAILED, ID NOT existing in Array, OLD ID kept
    QCOMPARE(acc01.linkBankAccount(tmpID02), false);


}
