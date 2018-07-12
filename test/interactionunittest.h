#ifndef INTERACTIONUNITTEST_H
#define INTERACTIONUNITTEST_H

#include <QtTest/QtTest>
#include <QObject>
#include "interactionunit.h"

class InteractionUnitTest : public QObject
{
    Q_OBJECT
    private slots:
    void cleanup();
    void testInitUserChoice();
    void testButtonPollingRoutine();
};

#endif // INTERACTIONUNITTEST_H
