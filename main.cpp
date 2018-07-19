#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QFile>


#if defined( USE_DATABASE )

#include "defaultcoffeemachine.h"

void setupApplicationState()
{
    bool ret;

    // Default Coffee Machine Init
    DefaultCoffeeMachine coffeeVendingMachine;

    ret = QFile::exists(DATABASE_NAME);

    // Creation the default DB from scratch with predefined records
    if (!ret) {
        ret = coffeeVendingMachine.createDefaulDB(DATABASE_NAME);
        if (ret) {
            qDebug() << "Default records created successfuly";
        }
        else {
            qDebug() << "Error creating default records for non-existing DB";
        }
    }

    // The DB now exists and the records from existing DB
    // will be loaded as class instances
    coffeeVendingMachine.restoreDefaultDB(DATABASE_NAME);

}

#else
#include "defaultcoffeemachinewithoutdb.h"

void setupApplicationState()
{
    DefaultCoffeeMachineWithoutDb coffeeVendingMachine;

    coffeeVendingMachine.createRecords();
}
#endif

int main(int argc, char *argv[])
{
    // Random Generator Init for Random ID Foo
    srand(time(NULL));
    setupApplicationState();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
