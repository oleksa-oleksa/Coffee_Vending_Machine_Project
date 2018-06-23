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
#include <string>

#define DATABASE_HOSTNAME "CoffeeMachine"
#define DATABASE_NAME "project_database.db"
#define DATABASE_NAME_TEST "project_database.db"

class Database : public QObject
{
    Q_OBJECT

    public:
        // Database(QObject *parent = 0);
        bool openDB(std::string db_name);
        bool deleteDB();
        void closeDatabase();
        QSqlError lastError();

        // Database create tables
        bool createPersonTable();
        bool createBankAccountTable();
        bool createAccountTable();
        bool createCardTable();

        // Adding the new rows to the existing tables
        bool insertPerson(QString name, QString surname,
                         QString address, int isEmployed, int isAdmin, int isStaff);
        bool insertBankAccount(QString accountID, int taxClass);
        bool insertAccount(QString accountID, QString personID, QString IBAN,
                           double credit, int state);
        bool insertCard(int cardStatus, QString accountID);

        bool loadPeople(People &people);
        bool loadBankAccounts(BAccounts &ba);
        bool loadAccounts(Accounts &a);
        bool loadCards(Cards &c);
        bool isOpen();
};

#endif
