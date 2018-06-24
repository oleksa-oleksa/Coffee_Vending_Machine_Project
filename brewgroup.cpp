#include "brewgroup.h"
#include <QDebug>

Brewgroup::Brewgroup()
{
    actuatorType = BREWGROUP;
    actuatorState = UNDEFINED;
    //actuatorduration =
    isOn = false;
}

Brewgroup::Brewgroup(bool isOn)
{
    this->isOn = isOn;
    this->actuatorType  = BREWGROUP;
    this->actuatorState = UNDEFINED;
    //actuatorduration  =
}

Brewgroup::~Brewgroup()
{

}

bool Brewgroup::getBrewgroupStatus() const
{
    if(this->isOn)
    {
       qDebug() << "The Brewgroup is On";
    }
   else
    {
        qDebug() << "The Brewgroup is Off";
    }

    return isOn;
}
