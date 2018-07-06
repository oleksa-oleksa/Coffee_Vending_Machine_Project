#ifndef OPTICALSENSORTEST_H
#define OPTICALSENSORTEST_H

#include <QtTest/QtTest>
#include <QObject>
#include "opticalsensor.h"


class OpticalSensorTest: public QObject
{
    Q_OBJECT
    private slots:
        //void testGetOpicalValue();
        void testGetOpticalSensorsMeasurement();

};

#endif // OPTICALSENSORTEST_H
