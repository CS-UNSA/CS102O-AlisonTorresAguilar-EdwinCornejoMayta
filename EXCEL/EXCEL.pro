#-------------------------------------------------
#
# Project created by QtCreator 2013-06-07T20:33:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EXCEL
TEMPLATE = app


SOURCES += main.cpp\
        excelwindow.cpp \
    cell.cpp \
    matrix.cpp \
    node.cpp \
    nodecell.cpp \
    nodenumber.cpp \
    nodeoperation.cpp \
    syntaxtree.cpp \
    parser.cpp

HEADERS  += excelwindow.h \
    cell.h \
    definedtypes.h \
    matrix.h \
    node.h \
    nodecell.h \
    nodenumber.h \
    nodeoperation.h \
    syntaxtree.h \
    parser.h

FORMS    += excelwindow.ui
