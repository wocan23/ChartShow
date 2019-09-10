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
#include <QScrollArea>


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

    // 坐标部分
    QSplitter *mainSplitter = new QSplitter;
    // left
    ChartLeftTree *chartLeftTree = new ChartLeftTree;
    // main
    ChartShow *chartShow = new ChartShow;
    QScrollArea * mainScrollArea = new QScrollArea;
    mainScrollArea->setWidgetResizable(true);
    mainScrollArea->setWidget(chartShow);
    // right
    ChartRight *chartRight = new ChartRight;
    QScrollArea * chartRightArea = new QScrollArea;
    chartRightArea->setWidgetResizable(true);
    chartRightArea->setWidget(chartRight);

    mainSplitter->addWidget(chartLeftTree);
    mainSplitter->addWidget(mainScrollArea);
    mainSplitter->addWidget(chartRightArea);

    mainSplitter->setStretchFactor(0,1);
    mainSplitter->setStretchFactor(1,9);
    mainSplitter->setStretchFactor(2,1);


    // bottom
    ChartBottom *bottom = new ChartBottom;

    fullLayout->addWidget(menu);
    fullLayout->addWidget(mainSplitter);
    fullLayout->addWidget(bottom);
    fullLayout->setStretchFactor(menu,1);
    fullLayout->setStretchFactor(mainSplitter,9);
    fullLayout->setStretchFactor(bottom,1);

    ui->centralWidget->setLayout(fullLayout);
    this->setBaseSize(800,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event){
    //qDebug() << this->menu->height();
}
