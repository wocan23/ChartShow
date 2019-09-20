#include "chartright.h"
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QTextDocument>
#include <QPainter>
#include "charthtextdocument.h"

ChartRight::ChartRight(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vboxLayout = new QVBoxLayout;

    QTabWidget *tabWidget = new QTabWidget;
    ChartHTextDocument *text1 = new ChartHTextDocument;
    QPlainTextEdit *text2 = new QPlainTextEdit("text2");


    tabWidget->addTab(text1,"t1");
    tabWidget->addTab(text2,"t2");
    vboxLayout->addWidget(tabWidget);
    this->setLayout(vboxLayout);
}

