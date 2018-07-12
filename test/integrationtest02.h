#ifndef INTEGRATIONTEST02_H
#define INTEGRATIONTEST02_H

#include <QObject>
#include <QtTest/QtTest>

class IntegrationTest02 : public QObject
{
    Q_OBJECT
private slots:
    void cleanup();
    void testMachineSetup();
};

#endif // INTEGRATIONTEST02_H
