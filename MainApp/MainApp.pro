#-------------------------------------------------
#
# Project created by QtCreator 2014-11-26T22:31:29
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    delegate.cpp

HEADERS  += mainwindow.h \
    delegate.h

FORMS    += mainwindow.ui
