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

        bool getButtonValue();
        void toggleButton();
        virtual void setSensorstate(State newState);
};

#endif // BUTTON_H
