#include "formgraph.h"
#include "ui_formgraph.h"
#include <cmath>
#include <qwt/qwt_plot_curve.h>
#include <qwt/qwt_plot_grid.h>

FormGraph::FormGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormGraph)
{
    ui->setupUi(this);
    QwtPlotCurve * curve1 = new QwtPlotCurve("I am an idiot");
    QVector<double> x = {-M_PI,-5*M_PI/6,-2*M_PI/3,-M_PI/2,-M_PI/3,-M_PI/6,0,M_PI/6,M_PI/3, M_PI/2,2*M_PI/3,5*M_PI/6,M_PI};
    QVector<double> y = {0, -0.5, -sqrt(3)/2,-1, -sqrt(3)/2, -0.5, 0, 0.5, sqrt(3)/2, 1, sqrt(3)/2, 0.5, 0};
    QwtPlotGrid *grid = new QwtPlotGrid();
    curve1->setSamples(x,y);
    curve1->attach(ui->qwtPlot);
    grid->attach(ui->qwtPlot);
}

FormGraph::~FormGraph()
{
    delete ui;
}
