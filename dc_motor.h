// Created by Oleksandra Baga
#ifndef DC_MOTOR_H
#define DC_MOTOR_H
#include <QObject>
#include "actuator.h"
#include "ingredient.h"

#define ROTATING_TIME_MS 250


enum MotorType {
    MOTOR_SUGAR = 0,
    MOTOR_MILK,
    MOTOR_COFFEE,
    MOTOR_CACAO,
    MOTOR_TYPES_NUMBER
};

class DC_Motor : public QObject, public Actuator
{
    Q_OBJECT

    private:
        MotorType motorType;
        bool isRotating;

    public:
        DC_Motor();
        virtual ~DC_Motor();
        void rotate(int componentAmount);
        bool getIsRotating();
        int calculateRotatingTime(int componentAmount);
        void setMotorType(MotorType motorType);

    public slots:
        bool rotatingDone();
};

#endif // DC_MOTOR_H
