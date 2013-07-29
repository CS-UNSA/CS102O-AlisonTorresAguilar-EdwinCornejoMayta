#ifndef UISPREADSHEET_H
#define UISPREADSHEET_H

#include <QTableWidget>

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

private:
    enum { MagicNumber = 0x7F51C883, RowCount = 999, ColumnCount = 26 };
};

#endif // UISPREADSHEET_H


