#include <QApplication>
#include <iostream>
//#include "parser.h"
#include "uimainwindow.h"
#include "cell.h"
#include "matrix.h"
#include "syntaxtree.h"

int main(int argc, char **argv)
{

    matrix excel (100,100);
    excel.insertCell(0,0,"50/2");
    excel.insertCell(0,1,"A1+7");
    excel.insertCell(0,2,"(A2+3)*A1");
    cout<<excel.getCell(0,0)->getValue()<<endl;
    cout<<excel.getCell(0,1)->getValue()<<endl;
    cout<<excel.getCell(0,2)->getValue()<<endl;

    cout<<"actualizacion"<<endl;
    excel.updateCell(0,0,"4+8");

    excel.insertCell(0,3,"A2+A1");
    // excel.updateCell(0,0,"A1+5");
    cout<<excel.getCell(0,0)->getValue()<<endl;
    cout<<excel.getCell(0,1)->getValue()<<endl;
    cout<<excel.getCell(0,2)->getValue()<<endl;

    cout<<excel.getCell(0,3)->getValue()<<endl;

    cout<<"actualizacion"<<endl;
    excel.updateCell(0,1,"sqrt(3,2)");

    cout<<excel.getCell(0,0)->getValue()<<endl;
    cout<<excel.getCell(0,1)->getValue()<<endl;
    cout<<excel.getCell(0,2)->getValue()<<endl;

    QApplication app(argc, argv);
    UIMainWindow mainWin;
    mainWin.show();
    return app.exec();

}
