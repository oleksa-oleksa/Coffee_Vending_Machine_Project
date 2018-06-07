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
        virtual ~Button();

        bool getButtonValue();
        void toggleButton();
};

#endif // BUTTON_H
