#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "formgraph.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void FileOpen();
    void FileExit();
    void FileConvert();
private:

    Ui::MainWindow *ui;
    FormGraph * graph;
};

#endif // MAINWINDOW_H
