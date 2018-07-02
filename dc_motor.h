#ifndef DC_MOTOR_H
#define DC_MOTOR_H
#include "actuator.h"
#include "ingredient.h"
#include <ctime>

enum MotorType {
    MOTOR_SUGAR,
    MOTOR_MILK,
    MOTOR_COFFEE,
    MOTOR_CACAO
};

class DC_Motor : public Actuator
{
    private:
        time_t stopRotationAt;

    public:
        DC_Motor();
        virtual ~DC_Motor();
        void rotate(int miliseconds);
        bool isRotating();
};

#endif // DC_MOTOR_H
