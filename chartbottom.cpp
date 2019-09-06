#include "chartbottom.h"
#include <QLabel>
#include <QHBoxLayout>

#define BOTTOM_TEXT  "图表展示"

ChartBottom::ChartBottom(QWidget *parent) : QWidget(parent)
{
    QLabel *label = new QLabel;
    label->setText(BOTTOM_TEXT);
    label->setAlignment(Qt::AlignHCenter);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);
    this->setLayout(layout);
}
