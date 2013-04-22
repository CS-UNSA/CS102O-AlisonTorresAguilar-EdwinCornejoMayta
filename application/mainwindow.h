 #ifndef MAINWINDOW_H
 #define MAINWINDOW_H

 #include <QMainWindow>

 class QAction;
 class QMenu;
 class QPlainTextEdit;
 class QToolBar;

 class MainWindow : public QMainWindow
 {
     Q_OBJECT

 public:
     MainWindow();

 protected:
     void closeEvent(QCloseEvent *event);

 private slots:
     void newFile();
     void open();
     bool save();
     bool saveAs();
     void about();
     void documentWasModified();

     void compile();

 private:
     void createActions();
     void createMenus();
     void createToolBars();
     void createStatusBar();

     void readSettings();
     void writeSettings();

     bool maybeSave();
     void loadFile(const QString &fileName);
     bool saveFile(const QString &fileName);
     void setCurrentFile(const QString &fileName);
     QString strippedName(const QString &fullFileName);

     QPlainTextEdit *textEdit;
     QString curFile;

     QMenu *fileMenu;
     QMenu *editMenu;
     QMenu *helpMenu;

     QMenu *compileMenu;

     QToolBar *fileToolBar;
     QToolBar *editToolBar;

     QToolBar *CompileToolBar;

     QAction *newAct;
     QAction *openAct;
     QAction *saveAct;
     QAction *saveAsAct;
     QAction *exitAct;
     QAction *cutAct;
     QAction *copyAct;
     QAction *pasteAct;
     QAction *aboutAct;
    // QAction *aboutQtAct;

     QAction *compileAct;
 };

 #endif
