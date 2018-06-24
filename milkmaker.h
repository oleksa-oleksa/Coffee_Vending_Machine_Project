#ifndef MILKMAKER_H
#define MILKMAKER_H
#include "actuator.h"
#include <string>
using namespace std;

class Milkmaker : public Actuator
{
public:
    Milkmaker();
    virtual ~Milkmaker();
};

#endif // MILKMAKER_H
