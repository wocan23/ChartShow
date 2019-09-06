#include "chartmenu.h"
#include <QHBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QDebug>

ChartMenu::ChartMenu(QWidget *parent) : QWidget(parent)
{

    QHBoxLayout *layout = new QHBoxLayout;

    QLabel *label = new QLabel;
    int w = label-> width();
    int h = label-> height();

    QPixmap *pixmap = new QPixmap(":/images/pic/chart.png");
    pixmap->scaled(h,h,Qt::KeepAspectRatio);
    label->setPixmap(*pixmap);

    label->setText("图表系统");
    layout->addWidget(label);

    this->setLayout(layout);


}
