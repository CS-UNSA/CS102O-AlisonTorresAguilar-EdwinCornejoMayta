#include <QApplication>
#include "mainwindow.h"

 int main(int argc, char *argv[])
 {
     Q_INIT_RESOURCE(application);

     QApplication app(argc, argv);
     app.setOrganizationName("Compiladores - Unsa");
     app.setApplicationName("E++");


     MainWindow w;
     w.show();


     return app.exec();
 }
