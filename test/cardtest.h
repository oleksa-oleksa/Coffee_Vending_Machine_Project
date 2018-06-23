#ifndef CARDTEST_H
#define CARDTEST_H

#include <QtTest/QtTest>
#include <QString>
#include <QObject>
#include "card.h"

class CardTest : public QObject
{
    Q_OBJECT
    private slots:
        void testDeactivateCard();
        void testActivateCard();
        void testWithdraw();
        void testLinkAccount();
};

#endif // CARDTEST_H
