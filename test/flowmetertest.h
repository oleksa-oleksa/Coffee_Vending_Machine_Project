#ifndef FLOWMETERTEST_H
#define FLOWMETERTEST_H

#include <QtTest/QtTest>
#include <QString>
#include <QObject>
#include "flowmeter.h"

class FlowmeterTest : public QObject
{
    Q_OBJECT
     private slots:
        void testSetRecipeAmountOfLiquid();
        void testMainFlowmeterRoutine();
};

#endif // FLOWMETERTEST_H
