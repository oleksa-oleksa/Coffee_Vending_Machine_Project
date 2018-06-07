#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H
#include <string>
#include "actuator.h"
using namespace std;

class LCD_Display : protected Actuator
{
public:
    LCD_Display();
    virtual ~LCD_Display();
    ActuatorType getActuatorType() const override;
    unsigned int getActuatorDuration() const override;
    State getActuatorState() const override;
    void setActuatorState(State actuator_state) override;
    void setActuatorDuration(unsigned int actuator_duration) override;
    void setActuatorType(ActuatorType actuator_Type) override;
    unsigned int get_xScreenPos() const;
    unsigned int get_yscreenPos() const;
    string get_title() const;
    string get_description() const;
    string get_errorMessage() const;

private:
    unsigned int xScreenPos = 0;
    unsigned int yScreenPos = 0;
    double price; //for what?
    string title;
    string description;
    string errorMessage;


};

#endif // LCD_DISPLAY_H
