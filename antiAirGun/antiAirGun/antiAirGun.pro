#-------------------------------------------------
#
# Project created by QtCreator 2013-04-11T17:34:59
#
#-------------------------------------------------

QT       += core gui widgets network multimedia

TARGET = antiAirGun
TEMPLATE = app


SOURCES += main.cpp \
    airGunTurret.cpp \
    gameWidget.cpp \
    airGun.cpp \
    shell.cpp \
    plane.cpp \
    enemyArmy.cpp \
    player.cpp \
    bomb.cpp \
    mainMenu.cpp \
    gifAnimation.cpp

HEADERS  += \
    airGunTurret.h \
    airGunBase.h \
    gameWidget.h \
    airGun.h \
    shell.h \
    plane.h \
    enemyArmy.h \
    myConsts.h \
    player.h \
    bomb.h \
    mainMenu.h \
    gifAnimation.h

RESOURCES += \
    resourses.qrc
