#ifndef SERVICEROUTINETEST_H
#define SERVICEROUTINETEST_H

#include <QtTest/QtTest>
#include <QObject>
#include "serviceroutine.h"


class ServiceRoutineTest: public QObject
{
    Q_OBJECT
    private slots:
        void testRefillOrNot();
};

#endif // SERVICEROUTINETEST_H
