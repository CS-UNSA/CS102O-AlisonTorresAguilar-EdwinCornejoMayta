#include <QApplication>
#include <iostream>
#include "parser.h"
#include "uimainwindow.h"

int main(int argc, char *argv[])
{

    int my_array[5] = {1, 2, 3, 4, 5};
    for (auto x : my_array)
        std::cout << x << std::endl;

    parser * my=new parser();
    my->buffer="5+((1+2)*4)-3"; // funciona ok
    my->buffer="-4*(-5-2)/(-1*x--3)"; // no evalua bien aun dobles signos
    my->buffer="tag(4.9)+8"; // funciona ok
    my->buffer="8%3"; // funciona ok

    cout<<"*****************"<<endl;
    my->getTokens();
    my->toPostfix();
    my->toBinaryTree();



    QApplication app(argc, argv);
    UIMainWindow mainWin;
    mainWin.show();
    return app.exec();
}
