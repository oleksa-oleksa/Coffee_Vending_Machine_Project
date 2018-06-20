/* Database designed and created by Oleksandra Baga */
#include "database.h"
#include <QDebug>
#include <QDir>
#include "QString"
#include "personid.h"
#include "bankaccountid.h"
#include "accountid.h"
#include "cardid.h"
#include "iostream"
#include "tools.h"

bool Database::createPersonTable()
{
    // Create table "Person"
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query(db);
        ret = query.exec("create table IF NOT EXISTS Person "
                         "(personID VARCHAR(5) NOT NULL primary key asc, "
                         "name VARCHAR(30) NOT NULL, "
                         "surname VARCHAR(50) NOT NULL, "
                         "address VARCHAR(100), "
                         "isEmployed INT, "
                         "isAdmin INT, "
                         "isStaff INT);");
        qDebug() << query.lastError().text();
     }
     qDebug() << "Table Person was created with exit code: " << ret;
     return ret;
}

bool Database::createBankAccountTable()
{
    // Create table "BankAccount"
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("create table IF NOT EXISTS BankAccount "
                         "(IBAN VARCHAR(22) NOT NULL, "
                         "accountID VARCHAR(12), "
                         "taxClass INT, "
                         "primary key (IBAN), "
                         "foreign key (accountID) references Account(accountID))");
        qDebug() << query.lastError().text();
     }
     qDebug() << "Table BankAccount was created with exit code: " << ret;
     return ret;
}

bool Database::createAccountTable()
{
    // Create table "Account"
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("create table IF NOT EXISTS Account "
                         "(accountID VARCHAR(12) NOT NULL, "
                         "personID  VARCHAR(5), "
                          "IBAN VARCHAR(22), "
                          "credit INT, "
                          "state INT, "
                          "primary key (accountID), "
                           "foreign key (personID) references Person(personID), "
                           "foreign key (IBAN) references BankAccount(IBAN))");
        qDebug() << query.lastError().text();
     }
     qDebug() << "Table Account was created with exit code: " << ret;
     return ret;
}


bool Database::createCardTable()
{
    // Create table "Account"
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("create table IF NOT EXISTS Card "
                         "(cardID VARCHAR(16) NOT NULL, "
                          "cardStatus INT NOT NULL, "
                          "accountID VARCHAR(12), "
                          "primary key (cardID), "
                          "foreign key (accountID) references Account(accountID))");
        qDebug() << query.lastError().text();
     }
     qDebug() << "Table Card was created with exit code: " << ret;
     return ret;
}

bool Database::insertPerson(QString name, QString surname,
                 QString address, int isEmployed, int isAdmin, int isStaff)
{
    bool ret = false;
    std::string personID = createRandomID(PERSON_ID_LEN);

    if (db.isOpen())
    {
           QSqlQuery query;
           // HINT: query.exec().arg().arg() => obj.arg().arg() => obj.arg()
           ret = query.exec(QString("insert into Person values('%1','%2', '%3', '%4', %5, %6, %7)")
           .arg(personID.c_str()).arg(name).arg(surname).arg(address).arg(isEmployed).arg(isAdmin).arg(isStaff));
           qDebug() << query.lastError().text();
     }
     qDebug() << "Insert into Person finished with exit code: " << ret;
     return ret;
}

bool Database::insertBankAccount(QString accountID, int taxClass)
{
    bool ret = false;
    std::string IBAN = createRandomID(IBAN_LEN);

    if (db.isOpen())
    {
           QSqlQuery query;
           ret = query.exec(QString("insert into BankAccount values('%1','%2', %3)")
           .arg(IBAN.c_str()).arg(accountID).arg(taxClass));
           qDebug() << query.lastError().text();
     }
     qDebug() << "Insert into BankAccount finished with exit code: " << ret;
     return ret;
}

bool Database::insertAccount(QString personID, QString IBAN, int credit, int state)
{
    bool ret = false;
    std::string accountID = createRandomID(ACCOUNT_ID_LEN);

    if (db.isOpen())
    {
           QSqlQuery query;
           ret = query.exec(QString("insert into Account values('%1','%2', '%3', %4, %5)")
           .arg(accountID.c_str()).arg(personID).arg(IBAN).arg(credit).arg(state));
           qDebug() << query.lastError().text();
    }
    qDebug() << "Insert into Account finished with exit code: " << ret;
    return ret;
}

bool Database::insertCard(int cardStatus, QString accountID)
{
    bool ret = false;
    std::string cardID = createRandomID(CARD_ID_LEN);

    if (db.isOpen())
    {
           QSqlQuery query;
           ret = query.exec(QString("insert into Card values('%1',%2, '%3'")
           .arg(cardID.c_str()).arg(cardStatus).arg(accountID));
           qDebug() << query.lastError().text();
    }
    qDebug() << "Insert into Card finished with exit code: " << ret;
    return ret;
}

bool Database::openDB()
{
    // Find QSLite driver
    db = QSqlDatabase::addDatabase("QSQLITE");

    #ifdef Q_OS_LINUX
   // NOTE: We have to store database file into user home folder in Linux
   QString path(QDir::home().path());
   path.append(QDir::separator()).append(DATABASE_NAME);
   path = QDir::toNativeSeparators(path);
   db.setDatabaseName(path);
   #else
   // NOTE: File exists in the application private folder, in Symbian Qt implementation
   qDebug() << QDir::currentPath();
   db.setDatabaseName(DATABASE_NAME);
   #endif

   // Open databasee
   bool ret = db.open();
   qDebug() << db.lastError().text();
   return ret;
}

QSqlError Database::lastError()
{
    // If opening database has failed user can ask
    // error description by QSqlError::text()
    return db.lastError();
}

bool Database::deleteDB()
{
    // Close database
    db.close();

    #ifdef Q_OS_LINUX
    // NOTE: We have to store database file into user home folder in Linux
    QString path(QDir::home().path());
    path.append(QDir::separator()).append("my.db.sqlite"DATABASE_NAME);
    path = QDir::toNativeSeparators(path);
    return QFile::remove(path);
    #else
    // Remove created database binary file
    return QFile::remove(DATABASE_NAME);
    #endif
}

void Database::closeDatabase()
{
    db.close();
}

bool Database::loadPeople(People &people)
{
    QSqlQuery query(db);

    bool ret = query.exec("SELECT personID, name, surname, address, isEmployed, isAdmin, isStaff FROM Person");

    if (!ret) {
        qDebug() << query.lastError().text();
        return ret;
    }

    while(query.next()) {
        QSqlRecord rec = query.record();
        Person p(rec);
        people.push_back(p);
    }

    qDebug() << "Loaded " << people.size() << " people";
    return ret;
}
