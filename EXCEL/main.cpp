#include <QApplication>
#include <iostream>
//#include "parser.h"
#include "uimainwindow.h"
#include "cell.h"
#include "matrix.h"
#include "syntaxtree.h"

int main()
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

    cout<<excel.getCell(0,0)->getValue()<<endl;
    cout<<excel.getCell(0,1)->getValue()<<endl;
    cout<<excel.getCell(0,2)->getValue()<<endl;

    /*
    QApplication app(argc, argv);
    UIMainWindow mainWin;
    mainWin.show();
    return app.exec();
    */
}
