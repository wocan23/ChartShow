#include "chartshow.h"

#include <QtCharts>
using namespace::QtCharts;
#include <QVBoxLayout>
#include <QBarSet>
#include <QBarSeries>
#include <QChart>
#include <QChartView>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QGuiApplication>
#include <QScreen>
#include <QPushButton>

ChartShow::ChartShow(QWidget *parent) : QWidget(parent)
{

    QVBoxLayout *vlayout = new QVBoxLayout;
    QStringList list;

    QPushButton *exportBtn = new QPushButton;
    exportBtn->setText("导出png");
    connect(exportBtn,SIGNAL(clicked()),this,SLOT(exportImageSlot()));

    vlayout->addWidget(exportBtn);
    vlayout->addWidget(this->drawBar(list,NULL,NULL,list));
    this->setLayout(vlayout);
}

QChartView* ChartShow:: drawBar(QStringList barSet, double**data,QString title, QStringList categorys){
    QBarSet *set0 = new QBarSet("Jane");
    QBarSet *set1 = new QBarSet("John");
    QBarSet *set2 = new QBarSet("Axel");
    QBarSet *set3 = new QBarSet("Mary");
    QBarSet *set4 = new QBarSet("Samantha");

    *set0 << 1 << 2 << 3 << 4 << 5 << 6;
    *set1 << 5 << 0 << 0 << 4 << 0 << 7;
    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
    *set4 << 9 << 7 << 5 << 3 << 1 << 2;

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple barchart example");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,15);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    this->chartView = chartView;
    return chartView;

}

void ChartShow::exportImage(QString path,IMAGE_FOMART format,QChartView *charView ){
    QPixmap p = charView->grab();
    QImage image = p.toImage();
    image.save("/Users/zhaoshuai/Documents/chart1.png");
}

void ChartShow::exportImageSlot(){
    exportImage("",PNG,this->chartView);
}

