#ifndef RFIDSCANNERTEST_H
#define RFIDSCANNERTEST_H

#include <QtTest/QtTest>
#include <QObject>
#include "rfid_scanner.h"


class RFIDScannerTest: public QObject
{
    Q_OBJECT
    private slots:
    void testEjectCard();
    void testInsertCard();
    void testIsvalidCardInside();
    void TestInitRFID();
};

#endif // RFIDSCANNERTEST_H
