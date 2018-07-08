#include "serviceroutine.h"
#include <QtDebug>

// refill if more than half empty

ServiceRoutine::ServiceRoutine() {
    qDebug() << "SERVICE_ROUTINE: Initiating tank service routine";
}

ServiceRoutine::~ServiceRoutine()
{
    qDebug() << "SERVICE_ROUTINE: Finalizing tank service routine";
}

void ServiceRoutine::refillOrNot(Ingredient *tankIngredient) {
    if (tankIngredient->getCacaoIngredient() < CACAO_TANK_AMOUNT * REFILL_THRESHOLD) {
        tankIngredient->refillCacaoTank();
        qDebug() << "Tank for Cacao was refilled!";
    }

    if (tankIngredient->getCoffeeIngredient() < COFFEE_TANK_AMOUNT * REFILL_THRESHOLD) {
        tankIngredient->refillCoffeeTank();
        qDebug() << "Tank for Coffee was refilled!";
    }

    if (tankIngredient->getMilkIngredient() < MILK_TANK_AMOUNT * REFILL_THRESHOLD) {
        tankIngredient->refillMilkTank();
        qDebug() << "Tank for Milk was refilled!";
    }

    if (tankIngredient->getSugarIngredient() < SUGAR_TANK_AMOUNT * REFILL_THRESHOLD) {
        tankIngredient->refillSugarTank();
        qDebug() << "Tank for Sugar was refilled!";
    }
}
