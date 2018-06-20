#ifndef DATABASETEST_H
#define DATABASETEST_H

#include <QtTest/QtTest>
#include <QString>
#include <QSqlError>
#include <QObject>
#include "database.h"

class DatabaseTest: public QObject
{
    Q_OBJECT
    private slots:
        void testOpenDB();
        //bool testRestoreDatabase();

        // Database create tables
        void testCreatePersonTable();
        void testCreateBankAccountTable();
        void testCreateAccountTable();
        void testCreateCardTable();

        // Adding the new rows to the existing tables
        void testInsertPerson();
        void testInsertBankAccount();
        void testInsertAccount();
        void testInsertCard();

        // Loading from DB into std::vector
        void testLoadPeople();
        void testLoadBankAccounts();


        void testCloseDatabase();
        // Uncomment to clear the DB after testing
        //void testDeleteDB();
};

#endif // DATABASETEST_H
