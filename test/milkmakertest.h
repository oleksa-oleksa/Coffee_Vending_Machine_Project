#ifndef MILKMAKERTEST_H
#define MILKMAKERTEST_H

#include <QtTest/QtTest>
#include <QString>
#include <QObject>
#include "milkmaker.h"

class MilkmakerTest : public QObject
{
    Q_OBJECT
    private slots:
        void testMakeMilkFoom();

};


#endif // MILKMAKERTEST_H
