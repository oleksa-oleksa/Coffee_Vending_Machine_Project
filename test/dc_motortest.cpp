#include "dc_motortest.h"

void DC_MotorTest::testRotate() {

    DC_Motor motor;


    while (!motor.getIsRotating()) {
        motor.rotate(0);
        QCoreApplication::instance()->processEvents();
        QCOMPARE(motor.getIsRotating(), true);
    }

    while (!motor.getIsRotating()) {
        motor.rotate(20);
        QCoreApplication::instance()->processEvents();
        QCOMPARE(motor.getIsRotating(), true);
    }

}

void DC_MotorTest::testCalculateRotatingTime() {

    DC_Motor motor;

    QCOMPARE(motor.calculateRotatingTime(5), 1250);
    QCOMPARE(motor.calculateRotatingTime(0), 0);
    QCOMPARE(motor.calculateRotatingTime(10), 2500);
    QCOMPARE(motor.calculateRotatingTime(-2), -500);
}
