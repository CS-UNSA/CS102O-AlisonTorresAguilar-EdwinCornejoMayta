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
                my->buffer="tag)45)+A3";
                cout<<"sss"<<endl;
                my->getTokens();

}

excelWindow::~excelWindow()
{
    delete ui;
}
