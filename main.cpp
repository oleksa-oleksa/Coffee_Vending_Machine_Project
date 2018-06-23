#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QFile>
#include "defaultcoffeemachine.h"


int main(int argc, char *argv[])
{
    bool ret;
    // Random Generator Init for Random ID Foo
    srand(time(NULL));

    // Default Coffee Machine Init
    DefaultCoffeeMachine coffeeVendingMachine;

    ret = QFile::exists(DATABASE_NAME);

    // Creation the default DB from scratch with predefined records
    if (!ret)
    {
        ret = coffeeVendingMachine.createDefaulDB(DATABASE_NAME);
        if (ret)
        {
            qDebug() << "Default records created successfuly";
        }
        else
        {
            qDebug() << "Error creating default records for non-existing DB";
        }
    }

    // The DB now exists and the records from existing DB
    // will be loaded as class instances
    coffeeVendingMachine.restoreDefaultDB(DATABASE_NAME);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
