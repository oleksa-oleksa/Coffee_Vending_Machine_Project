#ifndef BREWGROUP_H
#define BREWGROUP_H
#include "actuator.h"

class Brewgroup: protected Actuator
{

public:
    Brewgroup();
    virtual ~Brewgroup();
    ActuatorType getActuatorType() const override;
    unsigned int getActuatorDuration() const override;
    State getActuatorState() const override;
    int get_water_temperature() const;
    void set_water_temperature(int water_temperature);
    void setActuatorState(State actuator_state) override;
    void setActuatorDuration(unsigned int actuator_duration) override;
    void setActuatorType(ActuatorType actuator_Type) override;
    void start_stop(int status);

private:
    int status;
};

#endif // BREWGROUP_H
