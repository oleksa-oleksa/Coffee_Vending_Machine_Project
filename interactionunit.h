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

        Button *getMoreSugar() const;
        Button *getLessSugar() const;
        Button *getMoreMilk() const;
        Button *getLessMilk() const;
        Button *getCoffee() const;
        Button *getCappuccino() const;
        Button *getEspresso() const;
        Button *getLatteMacchiato() const;
        Button *getCacao() const;
        Button *getHotWater() const;
        Button *getBigPortion() const;
        Button *getStart() const;
};

extern InteractionUnit iunit;

#endif // INTERACTIONUNIT_H
