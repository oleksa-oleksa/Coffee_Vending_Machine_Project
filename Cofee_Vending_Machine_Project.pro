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
    mainwindow.ui

DISTFILES += \
    Cofee_Vending_Machine_Project.pro.user \
    README.md

HEADERS += \
    account.h \
    actuator.h \
    bankaccount.h \
    brewgroup.h \
    button.h \
    card.h \
    dc_motor.h \
    flowmeter.h \
    led.h \
    milkmaker.h \
    opticalsensor.h \
    pressuresensor.h \
    proximitysensor.h \
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
    indicationunit.h \
    interactionunit.h \
    person.h \
    sensortype.h \
    serviceroutine.h \
    staff.h \
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
    defaultcoffeemachine.h

SOURCES += \
    account.cpp \
    admin.cpp \
    actuatortype.cpp \
    bankaccount.cpp \
    card.cpp \
    controlunit.cpp \
    drink.cpp \
    indicationunit.cpp \
    interactionunit.cpp \
    person.cpp \
    sensortype.cpp \
    staff.cpp \
    userchoice.cpp \
    actuator.cpp \
    brewgroup.cpp \
    brightnesssensor.cpp \
    button.cpp \
    dc_motor.cpp \
    flowmeter.cpp \
    ingredient.cpp \
    lcd_display.cpp \
    led.cpp \
    milkmaker.cpp \
    opticalsensor.cpp \
    pressuresensor.cpp \
    proximitysensor.cpp \
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
    coffee.cpp

test {
    message(TEST BUILD)

    QT += testlib
    TARGET = Coffee-TEST

    SOURCES -= \
        main.cpp \
        mainwindow.cpp

    SOURCES += \
        test/testmain.cpp \
        test/mainwindow.cpp \
        test/databasetest.cpp \
        test/accounttest.cpp \
        test/bankaccounttest.cpp \
        test/cardtest.cpp \
        test/userchoicetest.cpp \
        test/interactionunittest.cpp


    HEADERS -= \
        mainwindow.h

    HEADERS += \
        test/mainwindow.h \
        test/databasetest.h \
        test/accounttest.h \
        test/bankaccounttest.h \
        test/cardtest.h \
        test/userchoicetest.h \
        test/interactionunittest.h

} else {
    message(NORMAL BUILD)
}

