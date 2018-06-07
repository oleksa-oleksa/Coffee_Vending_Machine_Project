#ifndef WATERHEATER_H
#define WATERHEATER_H
#include "actuator.h"

class Waterheater : protected Actuator
{
private:
    int water_temperature;

public:
    Waterheater();
    virtual ~Waterheater();
    ActuatorType getActuatorType() const override;
    unsigned int getActuatorDuration() const override;
    State getActuatorState() const override;
    int get_water_temperature() const;
    void set_water_temperature(int water_temperature);
    void setActuatorState(State actuator_state) override;
    void setActuatorDuration(unsigned int actuator_duration) override;
    void setActuatorType(ActuatorType actuator_Type) override;
};

#endif // WATERHEATER_H
