#ifndef BREWGROUP_H
#define BREWGROUP_H
#include "actuator.h"

class Brewgroup: public Actuator
{

public:
    Brewgroup();
    Brewgroup(bool isOn);
    virtual ~Brewgroup();
    bool getBrewgroupStatus() const;

private:
    bool isOn;
};

#endif // BREWGROUP_H
