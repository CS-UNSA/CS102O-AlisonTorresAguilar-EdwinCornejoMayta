#include "excelwindow.h"
#include "ui_excelwindow.h"
#include "parser.h"
#include <iostream>


excelWindow::excelWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::excelWindow)
{
    ui->setupUi(this);
    parser * my=new parser();
    my->buffer="5+((1+2)*4)-3"; // funciona ok
    my->buffer="-4*(-5-2)/(-1*x--3)"; // no evalua bien aun dobles signos
    my->buffer="tag(4.9)+8"; // funciona ok

    cout<<"----------------------------------------------------"<<endl;
    my->getTokens();
    cout<<"----------------------------------------------------"<<endl;
    my->toPostfix();
    cout<<"----------------------------------------------------"<<endl;


    //Esto es una prueba de la funcion para obtener su precedencia de un operador o funcion
    int p=my->getPrecedingFunction("tag");
    cout<<p<<" precedencia "<<endl;

}

excelWindow::~excelWindow()
{
    delete ui;
}
