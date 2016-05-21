#-------------------------------------------------
#
# Project created by QtCreator 2016-05-20T18:53:34
#
#-------------------------------------------------

QT       += core gui \
            svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CardGames
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    Card.cpp \
    Deck.cpp \
    blackjack.cpp \
    Hand.cpp \
    BlackjackHandEvaluator.cpp \
    poker.cpp

HEADERS  += mainwindow.h \
    Card.h \
    Deck.h \
    blackjack.h \
    Hand.h \
    BlackjackHandEvaluator.h \
    poker.h

FORMS    += mainwindow.ui \
    blackjack.ui \
    poker.ui

RESOURCES += \
    images.qrc

CONFIG += c++11
