#ifndef DC_MOTOR_H
#define DC_MOTOR_H
#include "actuator.h"

enum Motors {
    MOTOR_SUGAR,
    MOTOR_MILK,
    MOTOR_COFFEE,
    MOTOR_CACAO
};

class DC_Motor : public Actuator
{
public:
    DC_Motor();
    virtual ~DC_Motor();
    //bool rotate(DC_Motor motor);
};

#endif // DC_MOTOR_H
