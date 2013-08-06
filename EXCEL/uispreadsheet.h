#ifndef UISPREADSHEET_H
#define UISPREADSHEET_H

#include <QTableWidget>
#include <iostream>
#include "matrix.h"
QT_BEGIN_NAMESPACE
class UICell;
using namespace std;
QT_END_NAMESPACE

class UISpreadsheet : public QTableWidget
{
    Q_OBJECT

public:
    UISpreadsheet(QWidget *parent = 0);

    bool autoRecalculate() const { return autoRecalc; }
    QString currentLocation() const;
    QString currentFormula() const;
    QTableWidgetSelectionRange selectedRange() const;
    void clear();
    bool readFile(const QString &fileName);
    bool writeFile(const QString &fileName);
    //void sort(const SpreadsheetCompare &compare);

public slots:
    /**
     * @brief cut
     */
    void cut();

    /**
     * @brief copy
     */
    void copy();

    /**
     * @brief paste
     */
    void paste();

    /**
     * @brief del
     */
    void del();

    /**
     * @brief selectCurrentRow
     */
    void selectCurrentRow();

    /**
     * @brief selectCurrentColumn
     */
    void selectCurrentColumn();

    /**
     * @brief recalculate
     */
    void recalculate();

    /**
     * @brief setAutoRecalculate
     * @param recalc
     */
    void setAutoRecalculate(bool recalc);

    /**
     * @brief findNext
     * @param str
     * @param cs
     */
    void findNext(const QString &str, Qt::CaseSensitivity cs);

    /**
     * @brief findPrevious
     * @param str
     * @param cs
     */
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

signals:
    /**
     * @brief modified
     */
    void modified();

private slots:
    /**
     * @brief somethingChanged
     */
    void somethingChanged();

private:
    enum { MagicNumber = 0x7F51C883, RowCount = 999, ColumnCount = 26 };
    /**
     * @brief value
     * @param row
     * @param column
     * @return
     */
    QVariant value(int row,int column) const;

    /**
     * @brief cell
     * @param row
     * @param column
     * @return
     */
    UICell *cell(int row, int column) const;

    /**
     * @brief text
     * @param row
     * @param column
     * @return
     */
    QString text(int row, int column) const;

    /**
     * @brief formula
     * @param row
     * @param column
     * @return
     */
    QString formula(int row, int column) const;

    /**
     * @brief setFormula
     * @param row
     * @param column
     * @param formula
     */
    void setFormula(int row, int column, const QString &formula);

    /**
     * @brief setValue
     * @param row
     * @param column
     * @param value
     */
    void setValue(int row, int column, const QVariant &value);

    /**
     * @brief spreadSheet
     */
    matrix * spreadSheet;
    bool autoRecalc;
    void updateStatus(QTableWidgetItem *item);
};


#endif
