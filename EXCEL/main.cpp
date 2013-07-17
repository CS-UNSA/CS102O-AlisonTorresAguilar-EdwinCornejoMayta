#include <QApplication>
#include <iostream>
//#include "parser.h"
#include "uimainwindow.h"
#include "cell.h"
#include "matrix.h"
#include "syntaxtree.h"

int main()
{


    /*
    parser * my=new parser();
    my->buffer="5+((1+2)*4)-3"; // funciona ok
    my->buffer="-4*(-5-2)/(-1*x--3)"; // no evalua bien aun dobles signos
    my->buffer="tag(4.9)+8"; // funciona ok
    my->buffer="8%3"; // funciona ok

    my->getTokens();
    my->toPostfix();
    my->toBinaryTree();
    */

    //syntaxTree tree;
    //tree.built("5+3");

    matrix excel (100,100);
    excel.insertCell(0,0,"(5+4)/3");
    excel.insertCell(0,1,"A1+7");
    excel.insertCell(0,2,"A2+3");
    cout<<"dir"<<excel.getCell(0,0)<<endl;
    cout<<"dir"<<excel.getCell(0,1)<<endl;
    cout<<"dir"<<excel.getCell(0,2)<<endl;
    cout<<excel.getCell(0,0)->getValue()<<endl;
    cout<<excel.getCell(0,1)->getValue()<<endl;
    cout<<excel.getCell(0,2)->getValue()<<endl;



    //syntaxTree tree;
    //tree.built("5+9");
    //cout<<"Resultado="<<tree.evaluateTree()<<endl;


    /*
    QApplication app(argc, argv);
    UIMainWindow mainWin;
    mainWin.show();
    return app.exec();
    */
}
