#ifndef INTERACTIONUNIT_H
#define INTERACTIONUNIT_H

#include "userchoice.h"


class InteractionUnit
{
    private:
        UserChoice *choise;
        Button addSugar;
        Button removeSugar;
        Button addMilk;
        Button removeMilk;
        Button coffee;
        Button cappuccino;
        Button espresso;
        Button latteMacchiato;
        Button cacao;
        Button hotWater;
        Button bigPortion;
        Button start;

    public:
        InteractionUnit();
        ~InteractionUnit();
        void ButtonPollingRoutine();
};

#endif // INTERACTIONUNIT_H
