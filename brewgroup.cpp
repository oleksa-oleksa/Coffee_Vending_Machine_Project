#include "brewgroup.h"

Brewgroup::Brewgroup()
{
    actuatorType = BREWGROUP;
    actuatorState = UNDEFINED;
    //actuatorduration =
}

Brewgroup::~Brewgroup()
{

}

void Brewgroup::startStop(int status)
{
    this->status = status;
}
