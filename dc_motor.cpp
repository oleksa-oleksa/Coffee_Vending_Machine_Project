// Created by Oleksandra Baga
#include "dc_motor.h"
#include "QDebug"
#include <math.h>
#include <QTimer>
#include <map>

std::map<MotorType, const char *> MOTOR_TYPE_NAMES = {
    {MOTOR_SUGAR, "SUGAR MOTOR"},
    {MOTOR_COFFEE, "COFFEE POWDER MOTOR"},
    {MOTOR_MILK, "MILK MOTOR"},
    {MOTOR_CACAO, "CACAO POWDER MOTOR"}
};


DC_Motor::DC_Motor() {
    actuatorState = UNDEFINED;
    actuatorType = DC_MOTOR;
    isRotating = false;
}

DC_Motor::~DC_Motor() {

}

void DC_Motor::rotate(int componentAmount) {
    qDebug() << "DC MOTOR: Starting motor rotation:" << MOTOR_TYPE_NAMES[motorType];

    int time = calculateRotatingTime(componentAmount);
    qDebug() << "DC MOTOR: Realtime motor simulation started:" << MOTOR_TYPE_NAMES[motorType] << "...";
    isRotating = true;
    QTimer::singleShot(time, this, &DC_Motor::rotatingDone);

}


int DC_Motor::calculateRotatingTime(int componentAmount) {

    int time = componentAmount * ROTATING_TIME_MS;
    qDebug() << "DC MOTOR:" << MOTOR_TYPE_NAMES[motorType] << "Component is set:" << componentAmount << "Rotating will last" << time << " ms";
    return time;
}

bool DC_Motor::getIsRotating() {
    return isRotating;
}

bool DC_Motor::rotatingDone() {

    isRotating = false;
    qDebug() << "DC MOTOR:: Realtime motor simulation done:" << MOTOR_TYPE_NAMES[motorType];
}

void DC_Motor::setMotorType(MotorType motorType) {
    this->motorType = motorType;
}
