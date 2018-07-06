#ifndef INGREDIENTTEST_H
#define INGREDIENTTEST_H
#include <QtTest/QtTest>
#include <QObject>
#include "ingredient.h"

class IngredientTest: public QObject
{
    Q_OBJECT
    private slots:
        void testRefillAllIngredients();
        void testRefillSugarTank();
        void testRefillCoffeeTank();
        void testRefillCacaoTank();
        void testRefillMilkTank();
};

#endif // INGREDIENTTEST_H
