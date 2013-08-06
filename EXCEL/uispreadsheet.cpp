#include <QtWidgets>

#include "uicell.h"
#include "uispreadsheet.h"

UISpreadsheet::UISpreadsheet(QWidget *parent)
    : QTableWidget(parent)
{
    autoRecalc = true;
    spreadSheet =new matrix(100,100);
    setItemPrototype(new UICell);
    setSelectionMode(ContiguousSelection);

    connect(this, SIGNAL(itemChanged(QTableWidgetItem *)),
            this, SLOT(somethingChanged()));

    clear();
}

QString UISpreadsheet::currentLocation() const
{
    return QChar('A' + currentColumn())
           + QString::number(currentRow() + 1);
}

QString UISpreadsheet::currentFormula() const
{
    return formula(currentRow(), currentColumn());
}

QTableWidgetSelectionRange UISpreadsheet::selectedRange() const
{
    QList<QTableWidgetSelectionRange> ranges = selectedRanges();
    if (ranges.isEmpty())
        return QTableWidgetSelectionRange();
    return ranges.first();
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

bool UISpreadsheet::readFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, tr("Spreadsheet"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(file.fileName())
                             .arg(file.errorString()));
        return false;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_3);

    quint32 magic;
    in >> magic;
    if (magic != MagicNumber) {
        QMessageBox::warning(this, tr("Spreadsheet"),
                             tr("The file is not a Spreadsheet file."));
        return false;
    }

    clear();

    quint16 row;
    quint16 column;
    QString str;

    QApplication::setOverrideCursor(Qt::WaitCursor);
    while (!in.atEnd()) {
        in >> row >> column >> str;
        setFormula(row, column, str);
    }
    QApplication::restoreOverrideCursor();
    return true;
}

bool UISpreadsheet::writeFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, tr("Spreadsheet"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(file.fileName())
                             .arg(file.errorString()));
        return false;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_4_3);

    out << quint32(MagicNumber);

    QApplication::setOverrideCursor(Qt::WaitCursor);
    for (int row = 0; row < RowCount; ++row) {
        for (int column = 0; column < ColumnCount; ++column) {
            QString str = formula(row, column);
            if (!str.isEmpty())
                out << quint16(row) << quint16(column) << str;
        }
    }
    QApplication::restoreOverrideCursor();
    return true;
}

/*
void UISpreadsheet::sort(const SpreadsheetCompare &compare)
{
    QList<QStringList> rows;
    QTableWidgetSelectionRange range = selectedRange();
    int i;

    for (i = 0; i < range.rowCount(); ++i) {
        QStringList row;
        for (int j = 0; j < range.columnCount(); ++j)
            row.append(formula(range.topRow() + i,
                               range.leftColumn() + j));
        rows.append(row);
    }

    qStableSort(rows.begin(), rows.end(), compare);

    for (i = 0; i < range.rowCount(); ++i) {
        for (int j = 0; j < range.columnCount(); ++j)
            setFormula(range.topRow() + i, range.leftColumn() + j,
                       rows[i][j]);
    }

    clearSelection();
    somethingChanged();
}
*/

void UISpreadsheet::cut()
{
    copy();
    del();
}

void UISpreadsheet::copy()
{
    QTableWidgetSelectionRange range = selectedRange();
    QString str;

    for (int i = 0; i < range.rowCount(); ++i) {
        if (i > 0)
            str += "\n";
        for (int j = 0; j < range.columnCount(); ++j) {
            if (j > 0)
                str += "\t";
            str += formula(range.topRow() + i, range.leftColumn() + j);
            cout<<str.toStdString()<<" to copy "<<endl;
        }
    }
    QApplication::clipboard()->setText(str);
}

void UISpreadsheet::paste()
{
    QTableWidgetSelectionRange range = selectedRange();
    QString str = QApplication::clipboard()->text();
    QStringList rows = str.split('\n');
    int numRows = rows.count();
    int numColumns = rows.first().count('\t') + 1;
    cout<<str.toStdString()<<" to paste "<<endl;

    if (range.rowCount() * range.columnCount() != 1
            && (range.rowCount() != numRows
                || range.columnCount() != numColumns)) {
        QMessageBox::information(this, tr("Spreadsheet"),
                tr("The information cannot be pasted because the copy "
                   "and paste areas aren't the same size."));
        return;
    }

    cout<<"hola-------------------------------"<<endl;
    
    for (int i = 0; i < numRows; ++i) {
        QStringList columns = rows[i].split('\t');
        cout<<"---"<<columns[0].toStdString();
      //  cout<<" tmb "<<columns[1].toStdString()<<endl;
        cout<<numRows<<"filas to copy"<<endl;
        for (int j = 0; j < numColumns; ++j) {
            int row = range.topRow() + i;
            cout<<"row"<<row<<endl;
            int column = range.leftColumn() + j;
            if (row < RowCount && column < ColumnCount)
                setFormula(row, column, columns[j]);
            //somethingChanged();
               // cout<<columns[j].toStdString()<<"should paste "<<endl;
        }
    }
   // somethingChanged();
}

void UISpreadsheet::del()
{
    QList<QTableWidgetItem *> items = selectedItems();
    if (!items.isEmpty()) {
        foreach (QTableWidgetItem *item, items)
            delete item;
        somethingChanged();
    }
}

void UISpreadsheet::selectCurrentRow()
{
    selectRow(currentRow());
}

void UISpreadsheet::selectCurrentColumn()
{
    selectColumn(currentColumn());
}

void UISpreadsheet::recalculate()
{
    for (int row = 0; row < RowCount; ++row) {
        for (int column = 0; column < ColumnCount; ++column) {
            if (cell(row, column))
                cell(row, column)->setDirty();
        }
    }
    viewport()->update();
}

void UISpreadsheet::setAutoRecalculate(bool recalc)
{
    autoRecalc = recalc;
    if (autoRecalc)
        recalculate();
}

void UISpreadsheet::findNext(const QString &str, Qt::CaseSensitivity cs)
{
    int row = currentRow();
    int column = currentColumn() + 1;

    while (row < RowCount) {
        while (column < ColumnCount) {
            if (text(row, column).contains(str, cs)) {
                clearSelection();
                setCurrentCell(row, column);
                activateWindow();
                return;
            }
            ++column;
        }
        column = 0;
        ++row;
    }
    QApplication::beep();
}

void UISpreadsheet::findPrevious(const QString &str,
                               Qt::CaseSensitivity cs)
{
    int row = currentRow();
    int column = currentColumn() - 1;

    while (row >= 0) {
        while (column >= 0) {
            if (text(row, column).contains(str, cs)) {
                clearSelection();
                setCurrentCell(row, column);
                activateWindow();
                return;
            }
            --column;
        }
        column = ColumnCount - 1;
        --row;
    }
    QApplication::beep();
}

void UISpreadsheet::somethingChanged()
{
    /*
    if (autoRecalc)
        recalculate();
        */
  //  emit modified();
   /*
    string currentF,currentT;

    currentF=formula(currentRow(),currentColumn()).toStdString();
    currentT=text(currentRow(),currentColumn()).toStdString();
    spreadSheet->insertCell(currentRow(),currentColumn(),currentF);

    //cout<<"******************************************************"<<endl;
    cout<<" formula  "<<currentF<<endl;
    cout<<" text     "<<currentT<<endl;
    double value=this->spreadSheet->getValueAt(currentRow(),currentColumn());

    cout<<" value    "<<value<<endl;

   // cout<<currentRow()<<" ";
   // cout<<currentColumn()<<endl;

    cout<<"***************************************************"<<endl;

*/

   UICell *c = cell(currentRow(),currentColumn());
   c->setCell(spreadSheet->getCell(currentRow(),currentColumn()));
   c->setWidget(this);
   // c->update();
    //cout<<" AQUI"<<c->formula().toStdString()<<endl;
    //setFormula(currentRow(),currentColumn(),"666");
    //cout<<"something changeeeeeeeeeeeeeeeeeeeeeeeeeeee"<<endl;
   this->setCurrentCell(currentRow()+1,currentColumn());



}

UICell *UISpreadsheet::cell(int row, int column) const
{
    return static_cast<UICell *>(item(row, column));
}

void UISpreadsheet::setFormula(int row, int column,
                             const QString &formula)
{
    UICell *c = cell(row, column);
    if (!c) {
        c = new UICell;
        setItem(row, column, c);
    }
    c->setFormula(formula);
}

QString UISpreadsheet::formula(int row, int column) const
{
    UICell *c = cell(row, column);
    if (c) {
        return c->formula();
    } else {
        return "";
    }
}

QString UISpreadsheet::text(int row, int column) const
{
    UICell *c = cell(row, column);
    if (c) {
        return c->text();
    } else {
        return "";
    }
}

QVariant UISpreadsheet::value(int row, int column) const
{
    UICell *c = cell(row, column);
    if (c) {
        return c->value();
    } else {
        return 0;
    }
}


void UISpreadsheet::setValue(int row, int column, const QVariant &value){
    UICell *c = cell(row, column);
    if (!c) {
        c = new UICell;
        setItem(row, column, c);
    }
    c->setValue(value);
}
/*
bool SpreadsheetCompare::operator()(const QStringList &row1,
                                    const QStringList &row2) const
{
    for (int i = 0; i < KeyCount; ++i) {
        int column = keys[i];
        if (column != -1) {
            if (row1[column] != row2[column]) {
                if (ascending[i]) {
                    return row1[column] < row2[column];
                } else {
                    return row1[column] > row2[column];
                }
            }
        }
    }
    return false;
}
*/

void UISpreadsheet::updateStatus(QTableWidgetItem *item)
{
    /*
   if (item && item == this->currentItem()) {
        statusBar()->showMessage(item->data(Qt::StatusTipRole).toString(), 1000);
        cellLabel->setText(tr("Cell: (%1)").arg(encode_pos(table->row(item), table->column(item))));
        cellLabel->setText(tr("Cell: (%1)").arg(encode_pos(this->row(item), this->column(item))));
    }*/
}

void UISpreadsheet::messageToShow(QString message){
    QMessageBox::information(this, tr("Spreadsheet"),
            (message));

}

