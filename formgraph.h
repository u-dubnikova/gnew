#ifndef FORMGRAPH_H
#define FORMGRAPH_H

#include <QWidget>

namespace Ui {
class FormGraph;
}

class FormGraph : public QWidget
{
    Q_OBJECT

public:
    explicit FormGraph(QWidget *parent = 0);
    ~FormGraph();

private:
    Ui::FormGraph *ui;
};

#endif // FORMGRAPH_H
