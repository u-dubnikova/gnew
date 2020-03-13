#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include "alcdata.h"
#include "convert.h"

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
    AlcData d;
    QString fileName = QFileDialog::getOpenFileName(this,
        "Open file with results", "",
        "ALC (*.alc);;All Files (*)");

    if (fileName.isEmpty())
               return;

    QFileInfo inputInfo(fileName);
    QString new_name= inputInfo.absolutePath()+"/"+inputInfo.baseName()+".alv";

    QString outputFileName = QFileDialog::getSaveFileName(this,
                                                       "Save results", new_name,
                                                       "ALV (*.alv);;All Files (*)");
    if (outputFileName.isEmpty())
           return;
    QFileInfo info(outputFileName);
    if (info.suffix().isEmpty())
        outputFileName += ".alv";
    try
    {
        AlcToAlv(fileName.toStdString(), outputFileName.toStdString());
    }
    catch (std::runtime_error& e)
    {
        QMessageBox::information(this, "Error",
            QString("Unable to convert files: ") + e.what());
        return;
    }
}
