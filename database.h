/* Database designed and created by Oleksandra Baga */
#ifndef DATABASE_H
#define DATABASE_H
#include "account.h"
#include <QObject>
#include <QDate>
#include <QFile>
#include <QDebug>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

#define DATABASE_HOSTNAME "CoffeeMachine"
#define DATABASE_NAME "project_database.db"



class Database : public QObject
{
    Q_OBJECT

    private:
        // Database object
         QSqlDatabase db;

    public:
        Database(QObject *parent = 0);
        ~Database();
        bool openDB();
        bool deleteDB();
        bool restoreDatabase();
        void closeDatabase();
        QSqlError lastError();

        // Database create tables
        bool createPersonTable();
        bool createBankAccountTable();
        bool createAccountTable();
        bool createCardTable();

        // Adding the new rows to the existing tables
        int insertPerson(QString firstname, QString lastname, int age);

};

#endif
