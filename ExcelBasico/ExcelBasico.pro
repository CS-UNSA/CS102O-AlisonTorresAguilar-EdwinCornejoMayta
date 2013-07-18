#-------------------------------------------------
#
# Project created by QtCreator 2013-07-17T20:07:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExcelBasico
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    uispreadsheet.cpp \
    syntaxtree.cpp \
    spreadsheet.cpp \
    parser.cpp \
    nodeoperation.cpp \
    nodenumber.cpp \
    nodecell.cpp \
    node.cpp \
    matrix.cpp \
    evaluator.cpp \
    cell.cpp \
    calctree.cpp

HEADERS  += \
    mainwindow.h \
    uispreadsheet.h \
    syntaxtree.h \
    spreadsheet.h \
    parser.h \
    nodeoperation.h \
    nodenumber.h \
    nodecell.h \
    node.h \
    matrix.h \
    evaluator.h \
    definedtypes.h \
    cell.h
