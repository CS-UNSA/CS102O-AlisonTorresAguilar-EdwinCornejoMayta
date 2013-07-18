
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "matrix.h"

class QAction;
class QLabel;
class UISpreadsheet;

class UIMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    UIMainWindow();

protected:

private slots:

   // void updateStatusBar();
   // void spreadsheetModified();

private:


    UISpreadsheet *spreadsheet;
    QLabel *locationLabel;
    QLabel *formulaLabel;
    //matrix *excel;// (100,100);


};

#endif
