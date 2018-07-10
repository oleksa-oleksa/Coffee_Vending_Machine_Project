#-------------------------------------------------
#
# Project created by QtCreator 2018-04-24T23:58:22
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cofee_Vending_Machine_Project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SUBDIRS += \
    Cofee_Vending_Machine_Project.pro

FORMS += \
    mainwindow.ui \
    adminwindow.ui \
    drinkwindow.ui \
    ingredientwindow.ui

DISTFILES += \
    Cofee_Vending_Machine_Project.pro.user \
    README.md

HEADERS += \
    account.h \
    actuator.h \
    bankaccount.h \
    button.h \
    card.h \
    dc_motor.h \
    flowmeter.h \
    milkmaker.h \
    opticalsensor.h \
    rfid_scanner.h \
    sensor.h \
    temperatursensor.h \
    userchoice.h \
    waterheater.h \
    accountstatus.h \
    actuatortype.h \
    admin.h \
    controlunit.h \
    drink.h \
    drinktype.h \
    interactionunit.h \
    person.h \
    sensortype.h \
    serviceroutine.h \
    state.h \
    brightnesssensor.h \
    cacao.h \
    cappuccino.h \
    coffee.h \
    espresso.h \
    hotwater.h \
    ingredient.h \
    lattemacchiato.h \
    lcd_display.h \
    mainwindow.h \
    cardid.h \
    cardstatus.h \
    database.h \
    accountid.h \
    tools.h \
    personid.h \
    bankaccountid.h \
    defaultcoffeemachine.h \
    adminwindow.h \
    employeecombobox.h \
    drinkwindow.h \
    preparationstatus.h \
    ingredientwindow.h

SOURCES += \
    account.cpp \
    admin.cpp \
    bankaccount.cpp \
    card.cpp \
    controlunit.cpp \
    drink.cpp \
    interactionunit.cpp \
    person.cpp \
    sensortype.cpp \
    userchoice.cpp \
    actuator.cpp \
    brightnesssensor.cpp \
    button.cpp \
    dc_motor.cpp \
    flowmeter.cpp \
    ingredient.cpp \
    lcd_display.cpp \
    milkmaker.cpp \
    opticalsensor.cpp \
    rfid_scanner.cpp \
    sensor.cpp \
    serviceroutine.cpp \
    temperatursensor.cpp \
    waterheater.cpp \
    main.cpp \
    mainwindow.cpp \
    cardid.cpp \
    database.cpp \
    accountid.cpp \
    tools.cpp \
    personid.cpp \
    bankaccountid.cpp \
    defaultcoffeemachine.cpp \
    coffee.cpp \
    adminwindow.cpp \
    cacao.cpp \
    cappuccino.cpp \
    lattemacchiato.cpp \
    hotwater.cpp \
    espresso.cpp \
    employeecombobox.cpp \
    drinkwindow.cpp \
    globalobjects.cpp \
    ingredientwindow.cpp \

test {
    message(TEST BUILD)

    QT += testlib
    TARGET = Coffee-TEST

    SOURCES -= \
        main.cpp \
        adminwindow.cpp \
        drinkwindow.cpp \
        mainwindow.cpp

    SOURCES += \
        test/testmain.cpp \
        test/adminwindow.cpp \
        test/drinkwindow.cpp \
        test/databasetest.cpp \
        test/accounttest.cpp \
        test/bankaccounttest.cpp \
        test/cardtest.cpp \
        test/userchoicetest.cpp \
        test/interactionunittest.cpp \
        test/rfidscannertest.cpp \
        test/opticalsensortest.cpp \
        test/controlunittest.cpp \
        test/admintest.cpp \
        test/serviceroutinetest.cpp \
        test/ingredienttest.cpp \
        test/systemtest.cpp \
        test/flowmetertest.cpp \
        test/lcdtest.cpp \
        test/milkmakertest.cpp \
        test/temperaturesensortest.cpp \
        test/dc_motortest.cpp


    HEADERS -= \
        adminwindow.h \
        drinkwindow.h \
        mainwindow.h

    HEADERS += \
        test/databasetest.h \
        test/adminwindow.h \
        test/drinkwindow.h \
        test/accounttest.h \
        test/bankaccounttest.h \
        test/cardtest.h \
        test/userchoicetest.h \
        test/interactionunittest.h \
        test/rfidscannertest.h \
        test/opticalsensortest.h \
        test/controlunittest.h \
        test/admintest.h \
        test/serviceroutinetest.h \
        test/ingredienttest.h \
        test/systemtest.h \
        test/flowmetertest.h \
        test/lcdtest.h \
        test/milkmakertest.h \
        test/temperaturesensortest.h \
        test/dc_motortest.h
}
else {
    message(NORMAL BUILD)
}

RESOURCES += \
    images.qrc
