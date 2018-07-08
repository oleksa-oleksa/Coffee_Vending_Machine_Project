// Created by Oleksandra Baga
#include "bankaccounttest.h"
#include "account.h"

void BankAccountTest::testLinkAccount() {
    Account acc01;
    Account acc02;
    Account::AllAccounts.push_back(acc01);
    Account::AllAccounts.push_back(acc02);

    BankAccount bacc01;

    bacc01.setAccountID(acc01.getAccountID());

    QVERIFY(bacc01.linkAccount());
    qDebug() << "VERIFY: Linked Account ID is: " << bacc01.getAccount()->getAccountID().toQstring();

    bacc01.setAccountID(acc02.getAccountID());

    QVERIFY(bacc01.linkAccount());
    qDebug() << "VERIFY: Linked Account ID is: " << bacc01.getAccount()->getAccountID().toQstring();

}

void BankAccountTest::testLinkProvidedAccount() {
    Account acc01;
    Account acc02;
    Account::AllAccounts.push_back(acc01);
    Account::AllAccounts.push_back(acc02);

    AccountID accID01; // Random not existing in global array
    BankAccount bacc01;

    QCOMPARE(bacc01.linkProvidedAccount(acc01.getAccountID()), true);
    QCOMPARE(bacc01.linkProvidedAccount(accID01), false);
}
