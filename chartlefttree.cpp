#include "chartlefttree.h"
#include <QString>
#include <QStringList>
#include <QTreeWidgetItem>
#include "common.h"


ChartLeftTree::ChartLeftTree(QTreeWidget *parent) : QTreeWidget(parent)
{
     QStringList chartNames = { "bar","pie","line" };

    int size = chartNames.size();
    for(int i = 0; i < size; ++i){
        QString chartName = chartNames.at(i);
        QTreeWidgetItem * item = new QTreeWidgetItem(this);
        item->setText(0,chartName);
        item->setIcon(0,QIcon(CHART_ICON_PATH));
    }
    this->setHeaderHidden(true);




}
