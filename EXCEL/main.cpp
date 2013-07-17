#include <QApplication>
#include <iostream>
//#include "parser.h"
#include "uimainwindow.h"
<<<<<<< HEAD
#include "cell.h"
#include "matrix.h"
#include "syntaxtree.h"
=======
//#include "matrix.h"
>>>>>>> 3c4e6badd4550db674e5bdf7ab536d749d3c2cb7

int main()
{


    /*
    parser * my=new parser();
    my->buffer="5+((1+2)*4)-3"; // funciona ok
    my->buffer="-4*(-5-2)/(-1*x--3)"; // no evalua bien aun dobles signos
    my->buffer="tag(4.9)+8"; // funciona ok
    my->buffer="8%3"; // funciona ok

<<<<<<< HEAD
=======
//    excel =new matrix();

    cout<<"*****************"<<endl;
>>>>>>> 3c4e6badd4550db674e5bdf7ab536d749d3c2cb7
    my->getTokens();
    my->toPostfix();
    my->toBinaryTree();
    */

    //syntaxTree tree;
    //tree.built("5+3");

    matrix excel (100,100);

<<<<<<< HEAD
    excel.insertCell(0,0,"(5+4)/3");
    excel.insertCell(0,1,"(36-6)/4");
    cout<<excel.getCell(0,0)->getValue()<<endl;
    cout<<excel.getCell(0,1)->getValue()<<endl;


    //syntaxTree tree;
    //tree.built("5+9");
    //cout<<"Resultado="<<tree.evaluateTree()<<endl;


    /*
    QApplication app(argc, argv);
    UIMainWindow mainWin;
    mainWin.show();
    return app.exec();
    */
=======
/*    QApplication app(argc, argv);
    UIMainWindow mainWin;
    mainWin.show();
    return app.exec();*/
    return 0;
>>>>>>> 3c4e6badd4550db674e5bdf7ab536d749d3c2cb7
}
