#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    UIMainWindow mainWin;
    mainWin.show();
    return app.exec();
}
