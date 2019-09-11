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
#include <QList>

ChartShow::ChartShow(QWidget *parent) : QWidget(parent)
{

    QVBoxLayout *vlayout = new QVBoxLayout;
    QStringList list;



    // 测试图片数据
    QStringList barSetNames = {"Jane","John","Axel","Mary","Samantha"};
    QStringList categorys = {"Jan","Feb","Mar","Apr","May","Jun"};
    QList<QList<double>> datas;
    for (int i = 0; i < 5; ++i) {
        QList<double> tList;
        for (int j = 0; j < 6; j++) {
            tList.append(j - i + 10);
        }
        datas.append(tList);
    }
    // 测试图片数据

    vlayout->addWidget(this->drawBar(barSetNames,datas,"bar chart",categorys));

    QPushButton *exportBtn = new QPushButton;
    exportBtn->setText("导出png");
    connect(exportBtn,SIGNAL(clicked()),this,SLOT(exportImageSlot()));

    vlayout->addWidget(exportBtn);
    this->setLayout(vlayout);
}

QChartView* ChartShow:: drawBar(QStringList barSetNames, QList<QList<double>> data,QString title, QStringList categorys){
    double maxValue = 0;
    int barSetsize = barSetNames.size();
    int categorySize = categorys.size();
    QBarSet **barSets = new QBarSet*[barSetsize];
    for (int i = 0; i < barSetsize; ++i) {
        QBarSet *barSet = new QBarSet(barSetNames[i]);
        barSets[i] = barSet;
        for (int j = 0; j < categorySize; ++j) {
            *barSet<<data[i][j];
        }
    }

    QBarSeries *series = new QBarSeries();
    for (int i = 0; i < barSetsize; i++) {
         series->append(barSets[i]);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(title);
    chart->setAnimationOptions(QChart::SeriesAnimations);


    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categorys);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,maxValue*1.2);
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

