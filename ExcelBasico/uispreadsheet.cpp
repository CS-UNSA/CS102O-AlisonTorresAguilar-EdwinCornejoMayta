#include "uispreadsheet.h"
#include <iostream>
using namespace std;

UISpreadsheet::UISpreadsheet(QWidget *parent) :
    QTableWidget(parent)
{

    mat = new matrix(RowCount,ColumnCount);

    connect(this, SIGNAL(currentItemChanged(QTableWidgetItem*,QTableWidgetItem*)),
                this, SLOT(updateStatus(QTableWidgetItem*)));

    connect(this, SIGNAL(itemChanged(QTableWidgetItem *)),
            this, SLOT(somethingChanged()));
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

    cout<<"("<<currentColumn()<<","<<currentRow()<<")"<<endl;
    mat->insertCell(currentColumn(),currentRow(),currentItem()->text().toStdString());
    //mat->insertCell(currentColumn(),currentRow(),currentItem()->data(Qt::EditRole).toString().toStdString());
    cout<<"* "<<mat->getCell(currentColumn(),currentRow())->getValue()<<endl;
    cout<<"* "<<mat->getCell(currentColumn(),currentRow())->getExpression()<<endl;


    QString item1= QString::number(mat->getCell(currentRow(),currentColumn())->getValue());

    this->setItemPrototype(this->item(RowCount,ColumnCount));
   // this->setItem(currentRow(),currentColumn(),new QTableWidgetItem(item1));
    //table->adjustSize();
    //spreadsheet->resize(640,440);

    recalculate();
    viewport()->update();
    emit modified();

}

void UISpreadsheet::updateStatus(QTableWidgetItem *item)
{
   if (item && item == this->currentItem()) {
        statusBar()->showMessage(item->data(Qt::StatusTipRole).toString(), 1000);
        cellLabel->setText(tr("Cell: (%1)").arg(encode_pos(table->row(item), table->column(item))));
        cellLabel->setText(tr("Cell: (%1)").arg(encode_pos(this->row(item), this->column(item))));
    }
}
