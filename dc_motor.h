#ifndef DC_MOTOR_H
#define DC_MOTOR_H
#include "actuator.h"

class DC_Motor : protected Actuator
{
public:
    DC_Motor();
    virtual ~DC_Motor();
    bool startStop(int status);

private:
    int status;
};

#endif // DC_MOTOR_H
