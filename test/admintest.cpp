#include "admintest.h"

void AdminTest::init()
{
    admin = new Admin();
    BankAccount::AllBankAccounts.clear();
    Person::AllEmployee.clear();
    Account::AllAccounts.clear();
    Card::AllCards.clear();
}

void AdminTest::cleanup()
{
    Person::AllEmployee.clear();
    BankAccount::AllBankAccounts.clear();
    Account::AllAccounts.clear();
    Card::AllCards.clear();

    delete admin;
}

void AdminTest::testAddAccount() {
    Admin admin;
    Account acc;
    Person p;
    BankAccount ba;

    Person::AllEmployee.push_back(p);
    BankAccount::AllBankAccounts.push_back(ba);

    QVERIFY(Account::AllAccounts.empty());
    admin.addAccount(&acc);
    QVERIFY(Account::AllAccounts.size() == 1);
    Account &a = Account::AllAccounts[0];

    QCOMPARE(a.getOwner()->getID().toQstring(), p.getID().toQstring());
    QCOMPARE(a.getBankAccount()->getIBAN().toQstring(), ba.getIBAN().toQstring());


}

void AdminTest::testAddPerson() {

    qDebug() << "01: a Admin add a new Admin";
    Person person[2];

    QVERIFY(Person::AllEmployee.empty());
    admin->addPerson(&person[0], "Brice", "Dorsey", "BerlinerStrasse 20", true, false);
    QVERIFY(Person::AllEmployee.size() == 1);

    qDebug() << "02: a Admin add a new Person";
    Person person2;
    admin->addPerson(&person[1], "Long", "Dje", "kudamm 20", false, true);

    QVERIFY(Person::AllEmployee.size() == 2);

    for (int i=0; i < 2; i++) {
        QVERIFY(person[i].getName() == Person::AllEmployee[i].getName());
        QVERIFY(person[i].getSurname() == Person::AllEmployee[i].getSurname());
        QVERIFY(person[i].getAddress() == Person::AllEmployee[i].getAddress());
        QVERIFY(person[i].getAdmin() == Person::AllEmployee[i].getAdmin());
        QVERIFY(person[i].getStaff() == Person::AllEmployee[i].getStaff());
    }
}


void AdminTest::testAddBankAccount() {

    Account acc;
    BankAccountID bid;
    BankAccount ba;

    newAccount = &acc;

    ba.setIBAN(bid);

    QVERIFY(BankAccount::AllBankAccounts.empty());
    admin->addBankAccount(&ba, 2);
    QVERIFY(BankAccount::AllBankAccounts.size() == 1);


    BankAccount &sba = BankAccount::AllBankAccounts[0];
    QCOMPARE(sba.getTaxClass(), 2);
    QCOMPARE(sba.getAccountID().toQstring(), ba.getAccountID().toQstring());
}

void AdminTest::testAddCard()
{
    Account a;
    Card c;

    Account::AllAccounts.push_back(a);

    QVERIFY(Card::AllCards.empty());
    admin->addCard(&c);
    QVERIFY(Card::AllCards.size() == 1);
    QCOMPARE(Card::AllCards[0].getCardID().toQstring(),
            c.getCardID().toQstring());
    QCOMPARE(Card::AllCards[0].getAccount()->getAccountID().toQstring(),
            a.getAccountID().toQstring());
}
