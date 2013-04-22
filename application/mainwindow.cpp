#include <QtGui>
#include "mainwindow.h"
#include <iostream>

 MainWindow::MainWindow()
 {
     textEdit = new QPlainTextEdit;
     setCentralWidget(textEdit);

     createActions();
     createMenus();
     createToolBars();
     createStatusBar();

     readSettings();

     connect(textEdit->document(), SIGNAL(contentsChanged()),
             this, SLOT(documentWasModified()));

     setCurrentFile("");
 }

 void MainWindow::closeEvent(QCloseEvent *event)
 {
     if (maybeSave()) {
         writeSettings();
         event->accept();
     } else {
         event->ignore();
     }
 }

 void MainWindow::newFile()
 {
     if (maybeSave()) {
         textEdit->clear();
         setCurrentFile("");
     }
 }

 void MainWindow::open()
 {
     if (maybeSave()) {
         QString fileName = QFileDialog::getOpenFileName(this);
         if (!fileName.isEmpty())
             loadFile(fileName);
     }
 }

 bool MainWindow::save()
 {
     if (curFile.isEmpty()) {
         return saveAs();
     } else {
         return saveFile(curFile);
     }
 }

 bool MainWindow::saveAs()
 {
     QString fileName = QFileDialog::getSaveFileName(this);
     if (fileName.isEmpty())
         return false;

     return saveFile(fileName);
 }

 void MainWindow::about()
 {
    QMessageBox::about(this, tr("Acerca de"),
             tr("<b>Application</b> E++ Compiladores Unsa"));
 }

 void MainWindow::compile()
 {
    QMessageBox::about(this, tr("E++"),
             textEdit->toPlainText());
 }

 void MainWindow::documentWasModified()
 {
     setWindowModified(textEdit->document()->isModified());
 }

 void MainWindow::createActions()
 {
     newAct = new QAction(QIcon(":/images/new.png"), tr("&Nuevo"), this);
     newAct->setShortcuts(QKeySequence::New);
     newAct->setStatusTip(tr("Crear un nuevo fichero"));
     connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

     openAct = new QAction(QIcon(":/images/open.png"), tr("Abrir..."), this);
     openAct->setShortcuts(QKeySequence::Open);
     openAct->setStatusTip(tr("Abrir un fichero existente"));
     connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

     saveAct = new QAction(QIcon(":/images/save.png"), tr("&Guardar"), this);
     saveAct->setShortcuts(QKeySequence::Save);
     saveAct->setStatusTip(tr("Guardar el documento al disco"));
     connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

     saveAsAct = new QAction(tr("Guardar como..."), this);
     saveAsAct->setShortcuts(QKeySequence::SaveAs);
     saveAsAct->setStatusTip(tr("Guardar el documento con un nombre nuevo"));
     connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

     exitAct = new QAction(tr("Salir"), this);
     exitAct->setShortcuts(QKeySequence::Quit);
     exitAct->setStatusTip(tr("Salir de la aplicacion"));
     connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

     cutAct = new QAction(QIcon(":/images/cut.png"), tr("Cor&tar"), this);
     cutAct->setShortcuts(QKeySequence::Cut);
     cutAct->setStatusTip(tr("Cortar la seleccion actual y llevarla al "
                             "portapapeles"));
     connect(cutAct, SIGNAL(triggered()), textEdit, SLOT(cut()));

     copyAct = new QAction(QIcon(":/images/copy.png"), tr("&Copiar"), this);
     copyAct->setShortcuts(QKeySequence::Copy);
     copyAct->setStatusTip(tr("Copiar la seleccion actual y llevarla al "
                              "portapapeles"));
     connect(copyAct, SIGNAL(triggered()), textEdit, SLOT(copy()));

     pasteAct = new QAction(QIcon(":/images/paste.png"), tr("&Pegar"), this);
     pasteAct->setShortcuts(QKeySequence::Paste);
     pasteAct->setStatusTip(tr("Pegar la seleccion actual y llevarla al "
                               "portapapeles"));
     connect(pasteAct, SIGNAL(triggered()), textEdit, SLOT(paste()));

     aboutAct = new QAction(tr("&Acerca de"), this);
     aboutAct->setStatusTip(tr("Mostar Acerca de"));
     connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

     cutAct->setEnabled(false);
     copyAct->setEnabled(false);
     connect(textEdit, SIGNAL(copyAvailable(bool)),
             cutAct, SLOT(setEnabled(bool)));
     connect(textEdit, SIGNAL(copyAvailable(bool)),
             copyAct, SLOT(setEnabled(bool)));


     compileAct = new QAction(QIcon(":/images/ejecutar.png"), tr("&Ejecutar"), this);
     //compileAct->setShortcuts(QKeySequence(Qt::CTRL + Qt::Key_B));
     compileAct->setStatusTip(tr("Compila el programa!"));
     connect(compileAct, SIGNAL(triggered()), this, SLOT(compile()));//csmbiar el new file
 }

 void MainWindow::createMenus()
 {
     fileMenu = menuBar()->addMenu(tr("&Fichero"));
     fileMenu->addAction(newAct);
     fileMenu->addAction(openAct);
     fileMenu->addAction(saveAct);
     fileMenu->addAction(saveAsAct);
     fileMenu->addSeparator();
     fileMenu->addAction(exitAct);

     editMenu = menuBar()->addMenu(tr("&Editar"));
     editMenu->addAction(cutAct);
     editMenu->addAction(copyAct);
     editMenu->addAction(pasteAct);

     compileMenu = menuBar()->addMenu(tr("Ejecutar"));
     compileMenu->addAction(compileAct);

     menuBar()->addSeparator();

     helpMenu = menuBar()->addMenu(tr("Ayuda"));
     helpMenu->addAction(aboutAct);



 }

 void MainWindow::createToolBars()
 {
     fileToolBar = addToolBar(tr("Fichero"));
     fileToolBar->addAction(newAct);
     fileToolBar->addAction(openAct);
     fileToolBar->addAction(saveAct);

     editToolBar = addToolBar(tr("Editar"));
     editToolBar->addAction(cutAct);
     editToolBar->addAction(copyAct);
     editToolBar->addAction(pasteAct);

     CompileToolBar = addToolBar(tr("Ejecutar"));
     CompileToolBar->addAction(compileAct);
 }

 void MainWindow::createStatusBar()
 {
     statusBar()->showMessage(tr("Preparado"));
 }

 void MainWindow::readSettings()
 {
     QSettings settings("Trolltech", "Application ejemplo");
     QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
     QSize size = settings.value("size", QSize(400, 400)).toSize();
     resize(size);
     move(pos);
 }

 void MainWindow::writeSettings()
 {
     QSettings settings("Trolltech", "Application ejemplo");
     settings.setValue("pos", pos());
     settings.setValue("size", size());
 }

 bool MainWindow::maybeSave()
 {
     if (textEdit->document()->isModified()) {
         QMessageBox::StandardButton ret; // es un int con un codigo
         ret = QMessageBox::warning(this, tr("Application"),
                      tr("El documento ha sido modificado.\n"
                         "¿Quiere guardar los cambios?"),
                      QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
         if (ret == QMessageBox::Save)
             return save();
         else if (ret == QMessageBox::Cancel)
             return false;
     }
     return true;
 }

 void MainWindow::loadFile(const QString &fileName)
 {
     QFile file(fileName);
     if (!file.open(QFile::ReadOnly | QFile::Text)) {
         QMessageBox::warning(this, tr("Application"),
                              tr("No puedo leer el fichero %1:\n%2.")
                              .arg(fileName)
                              .arg(file.errorString()));
         return;
     }

     QTextStream in(&file);
     QApplication::setOverrideCursor(Qt::WaitCursor);
     textEdit->setPlainText(in.readAll());
     QApplication::restoreOverrideCursor();

     setCurrentFile(fileName);
     statusBar()->showMessage(tr("Fichero cargado"), 2000);
 }

 bool MainWindow::saveFile(const QString &fileName)
 {
     QFile file(fileName);
     if (!file.open(QFile::WriteOnly | QFile::Text)) {
         QMessageBox::warning(this, tr("Application"),
                              tr("No puedo escribir el fichero %1:\n%2.")
                              .arg(fileName)
                              .arg(file.errorString()));
         return false;
     }

     QTextStream out(&file);
     QApplication::setOverrideCursor(Qt::WaitCursor);
     out << textEdit->toPlainText();
     QApplication::restoreOverrideCursor();

     setCurrentFile(fileName);
     statusBar()->showMessage(tr("Fichero guardado"), 2000);
     return true;
 }

 void MainWindow::setCurrentFile(const QString &fileName)
 {
     curFile = fileName;
     textEdit->document()->setModified(false);
     setWindowModified(false);

     QString shownName = curFile;
     if (curFile.isEmpty())
         shownName = "untitled.txt";
     setWindowFilePath(shownName);
 }

 QString MainWindow::strippedName(const QString &fullFileName)
 {
     return QFileInfo(fullFileName).fileName();
 }
