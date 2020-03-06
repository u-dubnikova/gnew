#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), graph(nullptr)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FileOpen()
{
    if (graph == nullptr)
        graph = new FormGraph(nullptr);
    graph->show();
}

void MainWindow::FileExit()
{

}

void MainWindow::FileConvert()
{

}
