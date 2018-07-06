#ifndef ADMINTEST_H
#define ADMINTEST_H

#include <QtTest/QtTest>
#include <QObject>
#include "admin.h"

class AdminTest: public QObject
{
    Q_OBJECT
    private slots:
        void testAddPerson();
        void testAddBankAccount();

};

#endif // ADMINTEST_H
