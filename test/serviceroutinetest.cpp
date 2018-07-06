#include "serviceroutinetest.h"


void ServiceRoutineTest::testRefillOrNot() {

    ServiceRoutine svr;

    //Ingredient with true Parameter
    Ingredient *ingredient1 = new Ingredient(); // not needed to be refilled
    Ingredient *ingredient2 = new Ingredient(10, 5, 15, 1); //To refill all Ingredient
    Ingredient *ingredient3 = new Ingredient(); // some Ingredient have to be refiled
                ingredient3->setCacaoIngredient(0);
                ingredient3->setMilkIngredient(0);

    qDebug() << "01:";
    svr.refillOrNot(ingredient1);
    QCOMPARE(ingredient1->getSugarIngredient(), SUGAR_TANK_AMOUNT);
    QCOMPARE(ingredient1->getCoffeeIngredient(), COFFEE_TANK_AMOUNT);
    QCOMPARE(ingredient1->getCacaoIngredient(), CACAO_TANK_AMOUNT);
    QCOMPARE(ingredient1->getMilkIngredient(), MILK_TANK_AMOUNT);

    qDebug() << "02:";
    svr.refillOrNot(ingredient2);
    QCOMPARE(ingredient2->getSugarIngredient(), SUGAR_TANK_AMOUNT);
    QCOMPARE(ingredient2->getCoffeeIngredient(), COFFEE_TANK_AMOUNT);
    QCOMPARE(ingredient2->getCacaoIngredient(), CACAO_TANK_AMOUNT);
    QCOMPARE(ingredient2->getMilkIngredient(), MILK_TANK_AMOUNT);

    qDebug() << "03:";
    svr.refillOrNot(ingredient3);
    QCOMPARE(ingredient3->getCacaoIngredient(), CACAO_TANK_AMOUNT);
    QCOMPARE(ingredient3->getMilkIngredient(), MILK_TANK_AMOUNT);
}
