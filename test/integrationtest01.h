#ifndef INTEGRATIONTEST01_H
#define INTEGRATIONTEST01_H

#include <QtTest/QtTest>
#include <QObject>

class IntegrationTest01 : public QObject
{
    Q_OBJECT

private slots:
    void cleanup();
    void testBrewingDrink();
};

#endif // INTEGRATIONTEST01_H
