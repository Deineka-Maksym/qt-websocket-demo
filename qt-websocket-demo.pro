#-------------------------------------------------
#
# Project created by QtCreator 2017-08-09T14:33:01
#
#-------------------------------------------------

QT       += core gui websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-websocket-demo
TEMPLATE = app


SOURCES += main.cpp\
        MainDialog.cpp \
    ConnectionManager.cpp \
    EventGenerator.cpp

HEADERS  += MainDialog.h \
    ConnectionManager.h \
    EventGenerator.h

FORMS    += MainDialog.ui
