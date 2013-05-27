#-------------------------------------------------
#
# Project created by QtCreator 2013-05-20T20:43:31
#
#-------------------------------------------------

QT       += core gui

TARGET = EXCEL
TEMPLATE = app


SOURCES += main.cpp\
        excelwindow.cpp \
    node.cpp \
    nodenumber.cpp \
    nodecell.cpp \
    nodeoperation.cpp \
    cell.cpp \
    matrix.cpp \
    syntaxtree.cpp

HEADERS  += excelwindow.h \
    node.h \
    nodenumber.h \
    nodecell.h \
    nodeoperation.h \
    definedtypes.h \
    cell.h \
    matrix.h \
    syntaxtree.h

FORMS    += excelwindow.ui
