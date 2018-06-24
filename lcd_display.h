#ifndef LCD_DISPLAY_H
#define LCD_DISPLAY_H
#include <string>
#include "actuator.h"
using namespace std;

class LCD_Display : public Actuator
{
public:
    LCD_Display();
    virtual ~LCD_Display();
    unsigned int getXScreenPos() const;
    unsigned int getYscreenPos() const;
    string getTitle() const;
    string getDescription() const;
    string getErrorMessage() const;
    double getPrice() const;
    void setTitle(string title);
    void setDescription(string description);
    void setXScreenPos(unsigned int xSreenPos);
    void setYScreenPos(unsigned int yScreenPos);
    void setPrice(double price);
    void setErrorMessage(string errorMessage);

private:
    unsigned int xScreenPos = 0;
    unsigned int yScreenPos = 0;
    double price; //for what?
    string title;
    string description;
    string errorMessage;
};

#endif // LCD_DISPLAY_H
