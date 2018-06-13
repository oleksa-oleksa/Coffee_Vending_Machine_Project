#ifndef BREWGROUP_H
#define BREWGROUP_H
#include "actuator.h"

class Brewgroup: protected Actuator
{

public:
    Brewgroup();
    virtual ~Brewgroup();
    void startStop(int status);

private:
    int status;
};

#endif // BREWGROUP_H
