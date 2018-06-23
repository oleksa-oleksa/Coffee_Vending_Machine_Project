// Created by Oleksandra Baga
#ifndef ACCOUNTTEST_H
#define ACCOUNTTEST_H

#include <QtTest/QtTest>
#include <QObject>
#include "account.h"

class AccountTest: public QObject
{
    Q_OBJECT
    private slots:
        void testCheckCreditLimit();
        void testAddCredit();
        void testActivateAccount();
        void testDeactivateAccount();
        void testBlockAccount();
        void testLinkOwner();
        void testLinkBankAccount();
};

#endif // ACCOUNTTEST_H
