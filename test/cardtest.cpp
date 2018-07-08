#include "cardtest.h"
#include <QDebug>
#include "card.h"
#include "cardid.h"

void CardTest::testDeactivateCard() {
    Card test01;

    qDebug() << "01.";
    qDebug() << "Card status after default constructor:";
    test01.getCardStatus();

    test01.deactivateCard();
    qDebug() << "Card status after deactivateCard():";
    test01.getCardStatus();

}

void CardTest::testActivateCard() {
    Card test01;

    qDebug() << "02.";
    qDebug() << "Card status after default constructor:";
    test01.getCardStatus();

    test01.deactivateCard();
    qDebug() << "Card status after deactivateCard():";
    test01.getCardStatus();

    test01.activateCard();
    qDebug() << "Card status after activateCard():";
    test01.getCardStatus();

}

void CardTest::testWithdraw() {
    Account ts_acc01;
    Person ts_per01;

    Card test01;
    test01.setAccount(&ts_acc01);
    test01.getAccount()->setOwner(&ts_per01);

    // PASS
    // Default credit 0 + 5 < 10
    // isEmploeyd
    qDebug() << "01:";
    QCOMPARE(test01.withdraw(5.0), true);

    ts_acc01.setAccountCredit(9.0);
    // FAILED
    // Default credit 9 + 5 > 10
    // isEmploeyd
    qDebug() << "02:";
    QCOMPARE(test01.withdraw(5.0), false);

    ts_acc01.setAccountCredit(1.0);
    ts_per01.setEmployed(false);
    // FAILED
    // Default credit < 10
    // isEmploeyd = false
    qDebug() << "03:";
    QCOMPARE(test01.withdraw(5.0), false);
}

void CardTest::testLinkAccount() {
    Account ts_acc01;
    Account ts_acc02;

    AccountID ts_acid01; // pass
    AccountID ts_acid02; // pass
    AccountID ts_acid03; // used to fail test

    ts_acc01.setAccountID(ts_acid01);
    ts_acc02.setAccountID(ts_acid02);

    Account::AllAccounts.push_back(ts_acc01);
    Account::AllAccounts.push_back(ts_acc02);

    Card test01;

    QCOMPARE(test01.linkAccount(ts_acid01), true);
    QCOMPARE(test01.linkAccount(ts_acid02), true);
    QCOMPARE(test01.linkAccount(ts_acid03), false);

}
