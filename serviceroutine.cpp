#include "serviceroutine.h"
#include <QtDebug>

ServiceRoutine::ServiceRoutine()
{
    refillOrNot();
}

void ServiceRoutine::refillOrNot()
{
    if (this->tankIngredient->getCacaoIngredient() < 30)
    {
        this->tankIngredient->refillCacaoTank();
        qDebug() << "Tank for Cacao was refill!";
    }

    if (this->tankIngredient->getCoffeeIngredient() < 100)
    {
        this->tankIngredient->refillCoffeeTank();
        qDebug() << "Tank for Coffee was refill!";
    }

    if (this->tankIngredient->getMilkIngredient() < 50)
    {
        this->tankIngredient->refillMilkTank();
        qDebug() << "Tank for Milk was refill!";
    }

    if (this->tankIngredient->getSugarIngredient() < 50)
    {
        this->tankIngredient->refillSugarTank();
        qDebug() << "Tank for Sugar was refill!";
    }
}
