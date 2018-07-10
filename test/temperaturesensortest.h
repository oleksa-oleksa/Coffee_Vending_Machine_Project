#ifndef TEMPERATURESENSORTEST_H
#define TEMPERATURESENSORTEST_H

#include <QtTest/QtTest>
#include <QObject>
#include "temperatursensor.h"

class TemperatureSensorTest : public QObject
{
    Q_OBJECT
    private slots:
        void testCompareTemperatur();
};

#endif // TEMPERATURESENSORTEST_H
