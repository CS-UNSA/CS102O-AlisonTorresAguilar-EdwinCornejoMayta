#include "excelwindow.h"
#include "ui_excelwindow.h"

excelWindow::excelWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::excelWindow)
{
    ui->setupUi(this);
}

excelWindow::~excelWindow()
{
    delete ui;
}
