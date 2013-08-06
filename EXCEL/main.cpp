#include <QApplication>
#include <iostream>
//#include "parser.h"
#include "uimainwindow.h"
#include "cell.h"
#include "matrix.h"
#include "syntaxtree.h"

int main(int argc, char **argv)
{

/*
    matrix excel (100,100);
    excel.insertCell(0,0,"5");
    excel.insertCell(1,0,"=A1+1");
    excel.insertCell(2,0,"=A2+1");
    excel.insertCell(3,0,"=A3+1");
    excel.insertCell(4,0,"=A4+1");
    excel.insertCell(5,0,"=A2+A3");
    excel.insertCell(6,0,"=A5*A5");


    cout<<excel.getCell(0,0)->getValue()<<endl;
    cout<<excel.getCell(1,0)->getValue()<<endl;
    cout<<excel.getCell(2,0)->getValue()<<endl;
    cout<<excel.getCell(3,0)->getValue()<<endl;
    cout<<excel.getCell(4,0)->getValue()<<endl;
    cout<<excel.getCell(5,0)->getValue()<<endl;
    cout<<excel.getCell(6,0)->getValue()<<endl;

    cout<<"actualizacion"<<endl;
    excel.updateCell(0,0,"0");


    cout<<excel.getCell(0,0)->getValue()<<endl;
    cout<<excel.getCell(1,0)->getValue()<<endl;
    cout<<excel.getCell(2,0)->getValue()<<endl;
    cout<<excel.getCell(3,0)->getValue()<<endl;
    cout<<excel.getCell(4,0)->getValue()<<endl;
    cout<<excel.getCell(5,0)->getValue()<<endl;
    cout<<excel.getCell(6,0)->getValue()<<endl;

  */

    QApplication app(argc, argv);
    UIMainWindow mainWin;
    mainWin.show();
    return app.exec();

}
