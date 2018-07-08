#ifndef SYSTEMTEST_H
#define SYSTEMTEST_H
#include <QtTest/QtTest>
#include <QObject>
#include "serviceroutine.h"


class SystemTest: public QObject
{
    Q_OBJECT
    public:
        void createAllDependencies();

    private slots:
        void systemTest();
};
#endif // SYSTEMTEST_H
