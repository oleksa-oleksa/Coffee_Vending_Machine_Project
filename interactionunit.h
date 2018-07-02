#ifndef INTERACTIONUNIT_H
#define INTERACTIONUNIT_H

#include "userchoice.h"
#include "button.h"


class InteractionUnit
{
    private:
        UserChoice *choice;
        Button *moreSugar;
        Button *lessSugar;
        Button *moreMilk;
        Button *lessMilk;
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
        InteractionUnit *initInteractionUnit(Button *moreSugar,
                                             Button *lessSugar,
                                             Button *moreMilk,
                                             Button *lessMilk,
                                             Button *coffee,
                                             Button *cappuccino,
                                             Button *espresso,
                                             Button *latteMacchiato,
                                             Button *cacao,
                                             Button *hotWater,
                                             Button *bigPortion,
                                             Button *cancel,
                                             Button *start);
        UserChoice *initUserChoice(Card *card);
        bool abortSession();

        void setMoreSugar(Button *moreSugar);
        void setLessSugar(Button *lessSugar);
        void setMoreMilk(Button *addMilk);
        void setLessMilk(Button *lessMilk);
        void setCoffee(Button *coffee);
        void setCappuccino(Button *cappuccino);
        void setEspresso(Button *espresso);
        void setLatteMacchiato(Button *latteMacchiato);
        void setCacao(Button *cacao);
        void setHotWater(Button *hotWater);
        void setBigPortion(Button *bigPortio);
        void setCancel(Button *cancel);
        void setStart(Button *start);

        Button *getMoreSugar();
        Button *getLessSugar();
        Button *getMoreMilk();
        Button *getLessMilk();
        Button *getCoffee();
        Button *getCappuccino();
        Button *getEspresso();
        Button *getLatteMacchiato();
        Button *getCacao();
        Button *getHotWater();
        Button *getBigPortion();
        Button *getStart();
};

extern InteractionUnit iunit;

#endif // INTERACTIONUNIT_H
