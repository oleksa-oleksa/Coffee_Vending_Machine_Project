#ifndef MILKMAKER_H
#define MILKMAKER_H
#include "actuator.h"
#include <string>
using namespace std;

class Milkmaker : protected Actuator
{
public:
    Milkmaker();
    virtual ~Milkmaker();
    ActuatorType getActuatorType() const override;
    unsigned int getActuatorDuration() const override;
    State getActuatorState() const override;
    void setActuatorState(State actuator_state) override;
    void setActuatorDuration(unsigned int actuator_duration) override;
    void setActuatorType(ActuatorType actuator_Type) override;
    void start();
    void stop();
};

#endif // MILKMAKER_H
