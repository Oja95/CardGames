#-------------------------------------------------
#
# Project created by QtCreator 2016-05-20T18:53:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CardGames
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    Card.cpp

HEADERS  += mainwindow.h \
    Card.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc