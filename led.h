#ifndef LED_H
#define LED_H
#include "actuator.h"

class LED : protected Actuator
{
public:
    LED();
    virtual ~LED();
    ActuatorType getActuatorType() const override;
    unsigned int getActuatorDuration() const override;
    State getActuatorState() const override;
    void setActuatorState(State actuator_state) override;
    void setActuatorDuration(unsigned int actuator_duration) override;
    void setActuatorType(ActuatorType actuator_Type) override;
    void an_aus(int status);

private:
    int status; //für das an-und ausschalten
};

#endif // LED_H
