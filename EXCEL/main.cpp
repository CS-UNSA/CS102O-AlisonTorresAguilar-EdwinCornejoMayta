#include <QApplication>
#include <iostream>

#include "uimainwindow.h"

int main(int argc, char *argv[])
{

    int my_array[5] = {1, 2, 3, 4, 5};
    for (auto x : my_array)
        std::cout << x << std::endl;


    QApplication app(argc, argv);
    UIMainWindow mainWin;
    mainWin.show();
    return app.exec();
}
