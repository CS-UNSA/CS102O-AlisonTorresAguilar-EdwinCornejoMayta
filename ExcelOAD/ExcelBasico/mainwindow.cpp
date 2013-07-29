#include <QtWidgets>

#include "mainwindow.h"
#include "uispreadsheet.h"

UIMainWindow::UIMainWindow()
{
    spreadsheet = new UISpreadsheet;
    setCentralWidget(spreadsheet);



    setWindowIcon(QIcon(":/images/icon.png"));

}


//void UIMainWindow:: updateStatusBar(){}
//void UIMainWindow:: spreadsheetModified(){}
