#include "rfidscannertest.h"
#include <QDebug>
#include "account.h"

void RFIDScannerTest:: testInsertCard() {
    // wiht one Card multiple test and multiple Status
    RFID_Scanner rfid;

    Account acc01;
    Account::AllAccounts.push_back(acc01);

    Person per01;
    Person::AllEmployee.push_back(per01);
    per01.setName("Person01");

    Card card1;
    Card::AllCards.push_back(card1);
    card1.setAccount(&acc01);
    card1.getAccount()->setOwner(&per01);

    // The Card is allowed
    qDebug() << "01:";
    per01.setEmployed(true);
    card1.setCardStatus(ACTIVE);
    QCOMPARE(rfid.insertCard(&card1), true);

    // The Card is not allowed because the employee is not from the Company
    qDebug() << "02:";
    per01.setEmployed(false);
    QCOMPARE(rfid.insertCard(&card1), false);

    // the Card is not allowed because she is deactived
    qDebug() << "03:";
    card1.deactivateCard();
    QCOMPARE(rfid.insertCard(&card1), false);
}

void RFIDScannerTest::testEjectCard() {
    Account acc01;
    Account::AllAccounts.push_back(acc01);

    Person per01;
    Person::AllEmployee.push_back(per01);
    per01.setName("Person01");

    Card card1;
    Card::AllCards.push_back(card1);
    card1.setAccount(&acc01);
    card1.getAccount()->setOwner(&per01);

      RFID_Scanner rfid;
      rfid.insertCard(&card1);
      QCOMPARE(rfid.getIsCardInside(), true);

      rfid.ejectCard();
      QCOMPARE(rfid.getIsCardInside(), false);
}

void RFIDScannerTest::testIsvalidCardInside() {
    Account acc01;
    Account::AllAccounts.push_back(acc01);

    Person per01;
    Person::AllEmployee.push_back(per01);
    per01.setName("Person01");

    Card card1;
    Card::AllCards.push_back(card1);
    card1.setAccount(&acc01);
    card1.getAccount()->setOwner(&per01);

    RFID_Scanner rfid;
    rfid.insertCard(&card1);

    // Test with a true Card
    qDebug() << "01:";
    QCOMPARE(rfid.isValidCardInside(), true);

    // Test the RFID without Card
    qDebug() << "02:";
    rfid.ejectCard();
    QCOMPARE(rfid.isValidCardInside(), false);

    // Test the RFID with a false Card
    qDebug() << "03:";
    card1.setCardStatus(DEACTIVATED);
    rfid.insertCard(&card1);
    QCOMPARE(rfid.isValidCardInside(), false);

    // false empployed
    qDebug() << "04:";
    rfid.ejectCard();
    card1.getAccount()->getOwner()->setEmployed(false);
    rfid.insertCard(&card1);
    QCOMPARE(rfid.isValidCardInside(), false);
}

void RFIDScannerTest::TestInitRFID() {
    Account acc01;
    Account::AllAccounts.push_back(acc01);

    Person per01;
    Person::AllEmployee.push_back(per01);
    per01.setName("Person01");

    Card card1;
    Card::AllCards.push_back(card1);
    card1.setAccount(&acc01);
    card1.getAccount()->setOwner(&per01);

    RFID_Scanner rfid;

    // Test RFID without Card
    qDebug() << "01:";
    QCOMPARE(rfid.InitRFID(), NO_CARD);

    // Insert a valid Card
    qDebug() << "02:";
    rfid.insertCard(&card1);
    QCOMPARE(rfid.InitRFID(), VALID_CARD_INSIDE);
}
