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
                my->buffer="5+((1+2)*4)-3";
                my->buffer="-4*(-5-2)/(-1*x--3)";
                 my->buffer="tag(4)+8";
                cout<<"sss"<<endl;
                my->getTokens();

                int p=my->getPrecedingFunction("tag");
                cout<<p<<" precedencia "<<endl;
                my->toPostfix();


}

excelWindow::~excelWindow()
{
    delete ui;
}
