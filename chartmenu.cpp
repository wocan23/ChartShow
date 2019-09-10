#include "chartmenu.h"
#include <QHBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QDebug>

#define ICON_SIDE_LENGTH 45

ChartMenu::ChartMenu(QWidget *parent) : QWidget(parent)
{

    QHBoxLayout *layout = new QHBoxLayout;

    QLabel *label = new QLabel;

    QPixmap pixmap(":/images/pic/chart.png");
    QPixmap pixmap1 = pixmap.scaled(ICON_SIDE_LENGTH,ICON_SIDE_LENGTH,Qt::IgnoreAspectRatio);
    label->setPixmap(pixmap1);

    layout->addWidget(label);

    this->setLayout(layout);


}
