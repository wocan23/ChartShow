#include "chartright.h"
#include <QTextEdit>
#include <QVBoxLayout>
#include <QTabWidget>

ChartRight::ChartRight(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vboxLayout = new QVBoxLayout;

    QTabWidget *tabWidget = new QTabWidget;
    QTextEdit *text1 = new QTextEdit("text1");
    QTextEdit *text2 = new QTextEdit("text2");
    tabWidget->addTab(text1,"t1");
    tabWidget->addTab(text2,"t2");
    vboxLayout->addWidget(tabWidget);
    this->setLayout(vboxLayout);
}

