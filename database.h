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


class Dataset
{
    private:
        long dbID;
        Account *account;

    public:
        Dataset();
        ~Dataset();
        void addBill();
};

#endif
