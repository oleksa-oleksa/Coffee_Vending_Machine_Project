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
       std::string tmp_accID = createRandomID(ACCOUNT_ID_LEN);
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

    // Obtaining Foreign Keys
    for (size_t i = 0; i < people.size(); i++)
    {
       PersonID tmp_id = people[i].getID();
       QString q_pid = tmp_id.toQstring();

       //AccountID tmp_id2 = people[i].getID();
       //QString q_aid = tmp_id2.toQstring();

       //QVERIFY(db_t.insertBankAccount(q_pid, 1));
    }

}

void DatabaseTest::testInsertCard()
{

}

void DatabaseTest::testLoadPeople()
{
    Database db_t;
    db_t.openDB();

    // People is a type alias for vector of Person
    // See person.h
    People people;
    db_t.loadPeople(people);

    for (size_t i = 0; i < people.size(); i++) {
        people[i].getID();
        people[i].getName();
    }
}

void DatabaseTest::testCloseDatabase()
{
    Database db_t;
    db_t.closeDatabase();
}

// Uncomment to clear the DB after testing
/*
void DatabaseTest::testDeleteDB()
{
    Database db_t;
    QVERIFY(db_t.deleteDB());
}
*/
