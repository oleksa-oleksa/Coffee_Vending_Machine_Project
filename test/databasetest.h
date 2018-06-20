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
        //bool testDeleteDB();
        //bool testRestoreDatabase();
        void testCloseDatabase();

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

        void testLoadPeople();

};

#endif // DATABASETEST_H
