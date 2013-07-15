#ifndef EXCELWINDOW_H
#define EXCELWINDOW_H

#include <QMainWindow>

namespace Ui {
class excelWindow;
}

class excelWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit excelWindow(QWidget *parent = 0);
    ~excelWindow();
    
private:
    Ui::excelWindow *ui;
};

#endif // EXCELWINDOW_H
