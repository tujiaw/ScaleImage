#-------------------------------------------------
#
# Project created by QtCreator 2015-12-30T15:20:29
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtest
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h

FORMS    += dialog.ui

RESOURCES += \
    rc.qrc
