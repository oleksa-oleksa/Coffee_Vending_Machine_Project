#include "dc_motortest.h"

void DC_MotorTest::testRotate() {

    DC_Motor motor;
    motor.setMotorType(MOTOR_CACAO);

    motor.rotate(0);
    while (!motor.getIsRotating()) {
        QCoreApplication::instance()->processEvents();
        QCOMPARE(motor.getIsRotating(), true);
    }

    motor.rotate(20);
    while (!motor.getIsRotating()) {
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
