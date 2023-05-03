#-------------------------------------------------
#
# Project created by QtCreator 2019-08-23T16:09:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048game
TEMPLATE = app
RC_ICONS += logo.ico

SOURCES += main.cpp\
    ai.cpp \
    archivewidget.cpp \
        gamewidget.cpp \
    box.cpp \
    winwidget.cpp \
    losewidget.cpp \
    load.cpp \
    aboutwidget.cpp \
    welcome.cpp \
    rank.cpp

HEADERS  += gamewidget.h \
    ai.h \
    archivewidget.h \
    box.h \
    winwidget.h \
    losewidget.h \
    load.h \
    aboutwidget.h \
    welcome.h \
    rank.h

FORMS    += gamewidget.ui \
    archivewidget.ui \
    box.ui \
    winwidget.ui \
    losewidget.ui \
    load.ui \
    aboutwidget.ui \
    welcome.ui \
    rank.ui

RESOURCES += \
    image.qrc

CONFIG += C++11

DISTFILES += \
    uml_2048.qmodel
