#include "databasetest.h"
#include "database.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "tools.h"

void DatabaseTest::testOpenDB()
{
    Database db_t;

    QVERIFY2(db_t.openDB() == true, "OpenDB() failed");
}


/* bool DatabaseTest::testRestoreDatabase()
{

} */


void DatabaseTest::testCreatePersonTable()
{
    Database db_t;
    db_t.openDB();
    QVERIFY(db_t.createPersonTable());
}

void DatabaseTest::testCreateBankAccountTable()
{
    Database db_t;
    db_t.openDB();
    QVERIFY(db_t.createBankAccountTable());
}

void DatabaseTest::testCreateAccountTable()
{
    Database db_t;
    db_t.openDB();
    QVERIFY(db_t.createAccountTable());
}

void DatabaseTest::testCreateCardTable()
{
    Database db_t;
    db_t.openDB();
    QVERIFY(db_t.createCardTable());
}

void DatabaseTest::testInsertPerson()
{
    Database db_t;
    db_t.openDB();

    QVERIFY(db_t.insertPerson("Oleksandra", "EmployedAdmin", "Beuthstrasse 2018", 1, 1, 0));
    QVERIFY(db_t.insertPerson("Lara", "EmployedNormalPerson", "Kurze Strasse 22", 1, 0, 0));
    QVERIFY(db_t.insertPerson("Eugenia", "EmployedNormalPerson", "Teltowstrasse 12a", 1, 0, 0));
    QVERIFY(db_t.insertPerson("Vincent", "EmployedStaff", "Toller Strasse 2018", 1, 0, 1));
    QVERIFY(db_t.insertPerson("Patric", "UnemployedAtAll", "Tegeler Weg 17", 0, 0, 0));
    QVERIFY(db_t.insertPerson("Jack", "UnemployedStaff", "Schlossstrasse 36", 0, 0, 1));
    QVERIFY(db_t.insertPerson("Anetta", "UnemployedAdmin", "Bismarkstrasse 45", 0, 1, 0));
}

void DatabaseTest::testInsertBankAccount()
{
    Database db_t;
    db_t.openDB();

    // In Unit Test we want to know the amount of persons
    // in order to create exactly amount of BA
    People people;
    db_t.loadPeople(people);

    for (size_t i = 0; i < people.size(); i++)
    {
       std::string tmp_accID = std::string("ACC") + createRandomID(ACCOUNT_ID_LEN);
       QString str = QString::fromUtf8(tmp_accID.c_str());
       QVERIFY(db_t.insertBankAccount(str, 1));
    }
}

void DatabaseTest::testInsertAccount()
{
    Database db_t;
    db_t.openDB();
    People people;
    db_t.loadPeople(people);
    BAccounts ba;
    db_t.loadBankAccounts(ba);

    // Obtaining Foreign Keys
    // Bank Accounts and Account are always corresponding to the amount of people
    // this is the solution for this particular issue
    for (size_t i = 0; i < people.size(); i++)
    {
       AccountID tmp_id1 = ba[i].getAccountID();
       QString q_aid = tmp_id1.toQstring();

       BankAccountID tmp_id2 = ba[i].getIBAN();
       QString q_baid = tmp_id2.toQstring();

       PersonID tmp_id3 = people[i].getID();
       QString q_pid = tmp_id3.toQstring();

       QVERIFY(db_t.insertAccount(q_aid, q_pid, q_baid, 0.0, 0));
    }
}

void DatabaseTest::testInsertCard()
{

}

void DatabaseTest::testLoadPeople()
{
    Database db_t;
    db_t.openDB();

    // Saving from DB into static global
    QVERIFY(db_t.loadPeople(Person::AllEmployee));

}


void DatabaseTest::testLoadBankAccounts()
{
    Database db_t;
    db_t.openDB();

    // Saving from DB into static global
    QVERIFY(db_t.loadBankAccounts(BankAccount::AllBankAccounts));
}

void DatabaseTest::testLoadAccounts()
{
    Database db_t;
    db_t.openDB();

    QVERIFY(db_t.loadAccounts(Account::AllAccounts));

    // connect account and bank account verification
    for (size_t i = 0; i < Account::AllAccounts.size(); i++)
    {
        QVERIFY(Account::AllAccounts[i].getBankAccount()->linkProvidedAccount(Account::AllAccounts[i].getAccountID()));
    }
}

void DatabaseTest::testCloseDatabase()
{
    Database db_t;
    db_t.closeDatabase();
}

// Uncomment to clear the DB after testing
void DatabaseTest::testDeleteDB()
{
    Database db_t;
    QVERIFY(db_t.deleteDB());
}

