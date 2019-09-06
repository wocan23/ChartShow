#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QListWidget>
#include "chartlefttree.h"
#include "chartshow.h"
#include <QSplitter>
#include "chartbottom.h"
#include "chartright.h"
#include <QSizePolicy>


#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *fullLayout = new QVBoxLayout;

    // 标题部分
    ChartMenu *menu = new ChartMenu;
    this->menu = menu;
    QSizePolicy *p = new QSizePolicy;
    p->setVerticalPolicy(QSizePolicy::Expanding);
    menu->setSizePolicy(*p);


    // 坐标部分
    QSplitter *mainSplitter = new QSplitter;
    // left
    ChartLeftTree *chartLeftTree = new ChartLeftTree;
    // main
    ChartShow *chartShow = new ChartShow;
    // right
    ChartRight *chartRight = new ChartRight;

    mainSplitter->addWidget(chartLeftTree);
    mainSplitter->addWidget(chartShow);
    mainSplitter->addWidget(chartRight);
    mainSplitter->setStretchFactor(0,3);
    mainSplitter->setStretchFactor(1,7);
    mainSplitter->setStretchFactor(2,2);

    // bottom
    ChartBottom *bottom = new ChartBottom;

    fullLayout->setSpacing(1);
    fullLayout->addWidget(menu);
    fullLayout->addWidget(mainSplitter);
    fullLayout->addWidget(bottom);
    fullLayout->setStretchFactor(menu,1);
    fullLayout->setStretchFactor(mainSplitter,9);
    fullLayout->setStretchFactor(bottom,1);

    ui->centralWidget->setLayout(fullLayout);

    qDebug() << menu->height();
    qDebug() << mainSplitter->height();
    qDebug() << bottom->height();
    qDebug() << chartLeftTree->width();
    qDebug() << chartShow->width();
    qDebug() << chartRight->width();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event){
    qDebug() << this->menu->height();
}
