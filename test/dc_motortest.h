#ifndef DC_MOTORTEST_H
#define DC_MOTORTEST_H

#include <QtTest/QtTest>
#include <QObject>
#include "dc_motor.h"

class DC_MotorTest : public QObject
{
    Q_OBJECT
    private slots:
        void testRotate();
        void testCalculateRotatingTime();
};

#endif // DC_MOTORTEST_H
