#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QtGui>

class gui : public QMainWindow
{
    Q_OBJECT
public:
    explicit gui(int rows, int cols, QWidget *parent = 0);

private:
    QTableWidget *tabla;
    QToolBar *barraHerramientas;
    QLabel *etiquetaCelda;
    QLineEdit *ingresoFormula;



signals:
    
public slots:
    
};

#endif // GUI_H
