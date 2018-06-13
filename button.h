#ifndef BUTTON_H
#define BUTTON_H
#include "sensor.h"
class Button : public Sensor
{
    private:
        bool isPushed;
        int quantity;


    public:
        Button();
        Button(bool);
        virtual ~Button();

        bool getButtonValue();
        int getValue();
        void toggleButton();
};

#endif // BUTTON_H
