#include <QtGui/QApplication>
#include "gui.h"

int main(int argc, char** argv) {

    QApplication app(argc, argv);
    gui guiExcel(100,26);
    guiExcel.resize(640,480);
    guiExcel.show();

     return app.exec();
}

