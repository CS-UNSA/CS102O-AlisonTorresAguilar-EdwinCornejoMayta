#ifndef UISPREADSHEET_H
#define UISPREADSHEET_H

#include <QTableWidget>
#include "matrix.h"

class UISpreadsheet : public QTableWidget
{
    Q_OBJECT
public:
    UISpreadsheet(QWidget *parent = 0);
    void clear();

signals:
    void modified();

private slots:
    void somethingChanged();
    void updateStatus(QTableWidgetItem *item);

private:
    enum { MagicNumber = 0x7F51C883, RowCount = 999, ColumnCount = 26 };
    matrix *mat;
};

#endif // UISPREADSHEET_H


