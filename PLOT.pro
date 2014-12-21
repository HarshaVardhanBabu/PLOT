#-------------------------------------------------
#
# Project created by QtCreator 2014-12-06T16:48:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PLOT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    gnuplot-iostream.h

FORMS    += mainwindow.ui

LIBS += -L/usr/local/lib -lboost_iostreams -lboost_system -lboost_filesystem

