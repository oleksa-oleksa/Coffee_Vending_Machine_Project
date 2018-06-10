#ifndef WATERHEATER_H
#define WATERHEATER_H
#include "actuator.h"

class Waterheater : protected Actuator
{

public:
    Waterheater();
    virtual ~Waterheater();

};

#endif // WATERHEATER_H
