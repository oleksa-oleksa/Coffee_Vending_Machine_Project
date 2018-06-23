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
        void testAddCredit();
        void testCheckCreditLimit();
//        void testActivateAccount();
//        void testDeactivateAccount();
//        void testBlockAccount();
//        void testLinkOwner(PersonID personID);
//        void testLinkBankAccount(BankAccountID iban);
};

#endif // ACCOUNTTEST_H
