#ifndef INTERACTIONUNIT_H
#define INTERACTIONUNIT_H

#include "userchoice.h"
#include "button.h"


class InteractionUnit
{
    private:
        UserChoice *choice;

        Button *addSugar;
        Button *removeSugar;
        Button *addMilk;
        Button *removeMilk;
        Button *coffee;
        Button *cappuccino;
        Button *espresso;
        Button *latteMacchiato;
        Button *cacao;
        Button *hotWater;
        Button *bigPortion;
        Button *cancel;
        Button *start;

    public:
        InteractionUnit();
        ~InteractionUnit();

        void buttonPollingRoutine();
        UserChoice *initUserChoice(Card *card);
        bool abortSession();

        void setAddSugar(Button *addSugar);
        void setRemoveSugar(Button *removeSugar);
        void setAddMilk(Button *addMilk);
        void setRemoveMilk(Button *removeMilk);
        void setCoffee(Button *coffee);
        void setCappuccino(Button *cappuccino);
        void setEspresso(Button *espresso);
        void setLatteMacchiato(Button *latteMacchiato);
        void setCacao(Button *cacao);
        void setHotWater(Button *hotWater);
        void setBigPortion(Button *bigPortio);
        void setStart(Button *start);

        Button *getAddSugar();
        Button *getRemoveSugar();
        Button *getAddMilk();
        Button *getRemoveMilk();
        Button *getCoffee();
        Button *getCappuccino();
        Button *getEspresso();
        Button *getLatteMacchiato();
        Button *getCacao();
        Button *getHotWater();
        Button *getBigPortion();
        Button *getStart();
};

#endif // INTERACTIONUNIT_H
