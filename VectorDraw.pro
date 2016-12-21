#-------------------------------------------------
#
# Project created by QtCreator 2016-05-09T11:38:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VectorDraw
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    line.cpp \
    circle.cpp \
    shape.cpp

HEADERS  += mainwindow.h \
    line.h \
    circle.h \
    shape.h

FORMS    += mainwindow.ui

RESOURCES += \
    myicon.qrc
