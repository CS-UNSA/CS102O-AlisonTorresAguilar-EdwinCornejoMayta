#include <QtWidgets>

#include "mainwindow.h"
#include "uispreadsheet.h"

UIMainWindow::UIMainWindow()
{
    //excel = new matrix(100,100);

    spreadsheet = new UISpreadsheet;
    setCentralWidget(spreadsheet);



    setWindowIcon(QIcon(":/images/icon.png"));

}


//void UIMainWindow:: updateStatusBar(){}
//void UIMainWindow:: spreadsheetModified(){}
