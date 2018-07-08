#ifndef BUTTON_H
#define BUTTON_H
#include "sensor.h"
class Button : public Sensor
{
    private:
        bool isPushed;

    public:
        Button();
        Button(bool);

        bool getButtonValue() const;
        void toggleButton();
        virtual void setSensorState(State newState);
};

#endif // BUTTON_H
