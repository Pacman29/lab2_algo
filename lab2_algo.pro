#-------------------------------------------------
#
# Project created by QtCreator 2016-11-10T22:50:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab2_algo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    levenstein_algorithm.cpp

HEADERS  += mainwindow.h \
    levenshtein_algorithm.h

FORMS    += mainwindow.ui
