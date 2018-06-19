#include "databasetest.h"
#include "database.h"

void DatabaseTest::testOpenDB()
{
    Database db_t;

    QVERIFY2(db_t.openDB() == true, "OpenDB() failed");
}

/* bool DatabaseTest::testDeleteDB()
{

}
bool DatabaseTest::testRestoreDatabase()
{

} */
void DatabaseTest::testCloseDatabase()
{
    Database db_t;
    db_t.closeDatabase();

}

/*QSqlError DatabaseTest::testLastError()
{

}*/

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

    QVERIFY(db_t.insertPerson("Oleksandra", "Admin", "Beuth strasse 2018", 1, 1, 0));
    QVERIFY(db_t.insertPerson("Vicent", "Staff", "Toller strasse 2018", 1, 0, 1));
    QVERIFY(db_t.insertPerson("Patric", "Unemployed", "Grün Avenu 17", 0, 0, 0));
    QVERIFY(db_t.insertPerson("Patric", "UnemployedStaff", "Grün Avenu 17", 0, 0, 0));

}

void DatabaseTest::testInsertBankAccount()
{
    Database db_t;
    db_t.openDB();

    //QVERIFY(db_t.insertBankAccount());
}

void DatabaseTest::testInsertAccount()
{

}

void DatabaseTest::testInsertCard()
{

}
