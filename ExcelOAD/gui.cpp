
#include "gui.h"

gui::gui(int rows, int cols, QWidget *parent)
        : QMainWindow(parent)
{
    table = new QTableWidget(rows, cols, this);
    for (int c = 0; c < cols; ++c) {
        QString character(QChar('A' + c));
        table->setHorizontalHeaderItem(c, new QTableWidgetItem(character));
    }

    setWindowTitle(tr("CSExcel"));
}
