#ifndef DC_MOTOR_H
#define DC_MOTOR_H
#include "actuator.h"

class DC_Motor : protected Actuator
{
public:
    DC_Motor();
    virtual ~DC_Motor();
    ActuatorType getActuatorType() const override;
    unsigned int getActuatorDuration() const override;
    State getActuatorState() const override;
    void setActuatorState(State actuator_state) override;
    void setActuatorDuration(unsigned int actuator_duration) override;
    void setActuatorType(ActuatorType actuator_Type) override;
    void start();
    void stop();
};

#endif // DC_MOTOR_H
