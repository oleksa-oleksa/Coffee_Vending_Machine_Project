#include "database.h"
#include "QString"

bool Database::createPersonTable()
{
    // Create table "Person"
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("create table Person "
                         "(personID VARCHAR(5) NOT NULL, "
                         "name VARCHAR(30) NOT NULL, "
                          "surname VARCHAR(50) NOT NULL, "
                           "address VARCHAR(100), "
                           "isEmployed INT, "
                           "isAdmin INT, "
                           "isStaff INT, "
                           "primary key (personID))");
     }
     return ret;
}

bool Database::createBankAccountTable()
{
    // Create table "BankAccount"
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("create table BankAccount "
                         "(IBAN VARCHAR(22) NOT NULL, "
                         "accountID VARCHAR(12), "
                         "taxClass INT, "
                         "primary key (IBAN), "
                         "foreign key (accountID) references Account(accountID))");
     }
     return ret;
}

bool Database::createAccountTable()
{
    // Create table "Account"
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("create table Account "
                         "(accountID VARCHAR(12) NOT NULL, "
                         "personID  VARCHAR(5), "
                          "IBAN VARCHAR(22), "
                          "credit INT, "
                          "state INT, "
                          "primary key (accountID), "
                           "foreign key (personID) references Person(personID), "
                           "foreign key (IBAN) references BankAccount(IBAN))");
     }
     return ret;
}


bool Database::createCardTable()
{
    // Create table "Account"
    bool ret = false;
    if (db.isOpen())
    {
        QSqlQuery query;
        ret = query.exec("create table Card "
                         "(cardID VARCHAR(16) NOT NULL, "
                          "cardStatus INT NOT NULL, "
                          "accountID VARCHAR(12), "
                          "primary key (cardID), "
                          "foreign key (accountID) references Account(accountID))");
     }
     return ret;
}


bool Database::openDB()
{
    // Find QSLite driver
    db = QSqlDatabase::addDatabase(DATABASE_HOSTNAME);

    #ifdef Q_OS_LINUX
   // NOTE: We have to store database file into user home folder in Linux
   QString path(QDir::home().path());
   path.append(QDir::separator()).append(DATABASE_NAME);
   path = QDir::toNativeSeparators(path);
   db.setDatabaseName(path);
   #else
   // NOTE: File exists in the application private folder, in Symbian Qt implementation
   db.setDatabaseName(DATABASE_NAME);
   #endif

   // Open databasee
   return db.open();
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



