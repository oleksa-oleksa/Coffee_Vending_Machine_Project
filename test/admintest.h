#ifndef ADMINTEST_H
#define ADMINTEST_H

#include <QtTest/QtTest>
#include <QObject>
#include "admin.h"

class AdminTest: public QObject
{
    Q_OBJECT

    Admin *admin;

    private slots:
        void init();
        void cleanup();

        void testAddPerson();
        void testAddAccount();
        void testAddBankAccount();
        void testAddCard();
};

#endif // ADMINTEST_H
