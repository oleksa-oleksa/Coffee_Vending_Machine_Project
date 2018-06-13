#ifndef MILKMAKER_H
#define MILKMAKER_H
#include "actuator.h"
#include <string>
using namespace std;

class Milkmaker : protected Actuator
{
public:
    Milkmaker();
    virtual ~Milkmaker();
    bool startStop(int status);

private:
       int status;
};

#endif // MILKMAKER_H
