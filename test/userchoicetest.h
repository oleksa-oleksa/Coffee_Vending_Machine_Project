// Created by Oleksandra Baga
#ifndef USERCHOICETEST_H
#define USERCHOICETEST_H

#include <QtTest/QtTest>
#include <QObject>
#include "account.h"
#include "userchoice.h"

class UserChoiceTest : public QObject
{
    Q_OBJECT
    private slots:
        void testSetDefaultChoice();
        void testPayDrink();
        void testSetSelectedDrink();

        // setter and getters with conditional statements
        // depended from selected drink
        void testSetSugarAmount(int sugarAmount);
        int testGetSugarAmount();
        void testSetMilkAmount(int milkAmount);
        int testGetMilkAmount();
};

#endif // USERCHOICETEST_H
