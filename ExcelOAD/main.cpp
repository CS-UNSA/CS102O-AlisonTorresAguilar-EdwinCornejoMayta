#include <QtGui/QApplication>
#include "gui.h"

int main(int argc, char** argv) {

    QApplication app(argc, argv);
    gui guiExcel(10,10);
    guiExcel.resize(320,210);
    guiExcel.show();

     return app.exec();
}

