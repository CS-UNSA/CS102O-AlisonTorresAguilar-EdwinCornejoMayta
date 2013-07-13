
#include <QtWidgets>
#include "excelwindow.h"


excelWindow::excelWindow()
{
    spreadsheet = new Spreadsheet();
    setCentralWidget(spreadsheet);


    createActions();
    createMenus();
    createContextMenu();
    createToolBars();
    createStatusBar();

    setWindowIcon(QIcon(":/images/icon.png"));
    setCurrentFile("");

}

void excelWindow::closeEvent(QCloseEvent *event)
{

}

void excelWindow::newFile()
{

}

void excelWindow::open()
{

}

bool excelWindow::save()
{

}

bool excelWindow::saveAs()
{
}

void excelWindow::about()
{

}

void excelWindow::updateStatusBar()
{

}

void excelWindow::spreadsheetModified()
{
}

void excelWindow::createActions()
{

}

void excelWindow::createMenus()
{
}

void excelWindow::createContextMenu()
{

}

void excelWindow::createToolBars()
{

}

void excelWindow::createStatusBar()
{

}

bool excelWindow::loadFile(const QString &fileName)
{

    return true;
}

bool excelWindow::saveFile(const QString &fileName)
{

    return true;
}

void excelWindow::setCurrentFile(const QString &fileName)
{
}

void excelWindow::updateRecentFileActions()
{

}

QString excelWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}
