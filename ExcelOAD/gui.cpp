
#include "gui.h"

gui::gui(int rows, int cols, QWidget *parent)
        : QMainWindow(parent)
{
    addToolBar(barraHerramientas = new QToolBar());
    ingresoFormula = new QLineEdit();
    //ingresoFormula->setMinimumSize(100,0);
    ingresoFormula->setMaximumSize(280,25);
    etiquetaCelda = new QLabel(barraHerramientas);
    etiquetaCelda->setMinimumSize(80, 0);

    barraHerramientas->addWidget(etiquetaCelda);
    barraHerramientas->addWidget(ingresoFormula);

    tabla = new QTableWidget(rows, cols, this);
    tabla->move( mapToGlobal( QPoint( 0, 30 ) ) );
    for (int c = 0; c < cols; ++c) {
        QString character(QChar('A' + c));
        QString numero= QString::number(c+1);
        tabla->setHorizontalHeaderItem(c,new QTableWidgetItem(character));
        tabla->setVerticalHeaderItem(c, new QTableWidgetItem(numero));

    }
    tabla->setItemPrototype(tabla->item(rows -1, cols - 1));

//    table->adjustSize();
    tabla->resize(640,440);



    setWindowTitle(tr("CSExcel"));
}


