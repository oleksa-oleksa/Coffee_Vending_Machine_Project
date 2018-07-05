// Created by Oleksandra Baga
#ifndef BANKACCOUNTTEST_H
#define BANKACCOUNTTEST_H

#include <QtTest/QtTest>
#include <QString>
#include <QSqlError>
#include <QObject>
#include "bankaccount.h"
#include "controlunit.h"

class BankAccountTest: public QObject
{
    Q_OBJECT
    private slots:
        void testLinkAccount();
        void testLinkProvidedAccount();
};

#endif // BANKACCOUNTTEST_H
