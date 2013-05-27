#include <QtGui/QApplication>
#include "excelwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    excelWindow w;
    w.show();
    
    return a.exec();
}
