#include "ingredienttest.h"

void IngredientTest::testRefillAllIngredients()
{
    Ingredient ingredient1(0, 0, 0, 0);
    Ingredient ingredient2(10, 20, 10, 10);

    qDebug() << "01:";
    ingredient1.refillAllIngredients();
    QCOMPARE(ingredient1.getSugarIngredient(), SUGAR_TANK_AMOUNT);
    QCOMPARE(ingredient1.getCoffeeIngredient(), COFFEE_TANK_AMOUNT);
    QCOMPARE(ingredient1.getCacaoIngredient(), CACAO_TANK_AMOUNT);
    QCOMPARE(ingredient1.getMilkIngredient(), MILK_TANK_AMOUNT);

    qDebug() << "02:";
    ingredient2.refillAllIngredients();
    QCOMPARE(ingredient2.getSugarIngredient(), SUGAR_TANK_AMOUNT);
    QCOMPARE(ingredient2.getCoffeeIngredient(), COFFEE_TANK_AMOUNT);
    QCOMPARE(ingredient2.getCacaoIngredient(), CACAO_TANK_AMOUNT);
    QCOMPARE(ingredient2.getMilkIngredient(), MILK_TANK_AMOUNT);
}

void IngredientTest::testRefillSugarTank()
{
    Ingredient ingredient1(0, 0, 0, 0);
    Ingredient ingredient2(10, 20, 10, 10);

    qDebug() << "01:";
    ingredient1.refillSugarTank();
    QCOMPARE(ingredient1.getSugarIngredient(), SUGAR_TANK_AMOUNT);

    qDebug() << "02:";
    ingredient2.refillSugarTank();
    QCOMPARE(ingredient2.getSugarIngredient(), SUGAR_TANK_AMOUNT);
}

void IngredientTest::testRefillCoffeeTank()
{
    Ingredient ingredient1(0, 0, 0, 0);
    Ingredient ingredient2(10, 20, 10, 10);

    qDebug() << "01:";
    ingredient1.refillCoffeeTank();
    QCOMPARE(ingredient1.getCoffeeIngredient(), COFFEE_TANK_AMOUNT);

    qDebug() << "02:";
    ingredient2.refillCoffeeTank();
    QCOMPARE(ingredient2.getCoffeeIngredient(), COFFEE_TANK_AMOUNT);
}

void IngredientTest::testRefillCacaoTank()
{
    Ingredient ingredient1(0, 0, 0, 0);
    Ingredient ingredient2(10, 20, 10, 10);

    qDebug() << "01:";
    ingredient1.refillCacaoTank();
    QCOMPARE(ingredient1.getCacaoIngredient(), CACAO_TANK_AMOUNT);

    qDebug() << "02:";
    ingredient2.refillCacaoTank();
    QCOMPARE(ingredient2.getCacaoIngredient(), CACAO_TANK_AMOUNT);
}

void IngredientTest::testRefillMilkTank()
{
    Ingredient ingredient1(0, 0, 0, 0);
    Ingredient ingredient2(10, 20, 10, 10);

    qDebug() << "01:";
    ingredient1.refillMilkTank();
    QCOMPARE(ingredient1.getMilkIngredient(), MILK_TANK_AMOUNT);

    qDebug() << "02:";
    ingredient2.refillMilkTank();
    QCOMPARE(ingredient2.getMilkIngredient(), MILK_TANK_AMOUNT);
}
