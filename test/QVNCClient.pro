
QT       += core gui network websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QVNCClient
TEMPLATE = app

include(../src/qvncclientwidget.pri)

SOURCES += main.cpp             \
           mainwindow.cpp

HEADERS += mainwindow.h

FORMS   += mainwindow.ui
