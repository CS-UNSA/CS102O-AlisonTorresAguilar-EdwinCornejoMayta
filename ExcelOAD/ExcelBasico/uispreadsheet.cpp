#include "uispreadsheet.h"
#include <iostream>
using namespace std;

UISpreadsheet::UISpreadsheet(QWidget *parent) :
    QTableWidget(parent)
{


    connect(this, SIGNAL(itemChanged(QTableWidgetItem *)),
            this, SLOT(somethingChanged()));
 //   row(const QTableWidgetItem * item);
    clear();
}

void UISpreadsheet::clear()
{
    setRowCount(0);
    setColumnCount(0);
    setRowCount(RowCount);
    setColumnCount(ColumnCount);

    for (int i = 0; i < ColumnCount; ++i) {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString(QChar('A' + i)));
        setHorizontalHeaderItem(i, item);

    }
    setCurrentCell(0, 0);
}




void UISpreadsheet::somethingChanged(){

    cout<<"Modificado"<<endl;
    emit modified();
}
