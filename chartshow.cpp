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
#include <QFileDialog>

ChartShow::ChartShow(QWidget *parent) : QWidget(parent)
{
    this->chart = NULL;
    QVBoxLayout *vlayout = new QVBoxLayout;

    this->chartView = new QChartView;
    vlayout->addWidget(this->chartView);
    this->draw();

    QPushButton *exportBtn = new QPushButton;
    exportBtn->setText("导出png");
    connect(exportBtn,SIGNAL(clicked()),this,SLOT(exportImageSlot()));

    QPushButton *redrawBtn = new QPushButton;
    redrawBtn->setText("redrawBtn");
    connect(redrawBtn,SIGNAL(clicked()),this,SLOT(reDraw()));

    vlayout->addWidget(exportBtn);
    vlayout->addWidget(redrawBtn);
    this->setLayout(vlayout);
}

QChart* ChartShow:: drawBar(QStringList barSetNames, QList<QList<double>> data,QString title, QStringList categorys){
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
//    axisY->setRange(0,maxValue*1.2);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    return chart;

}

void ChartShow::exportImage(QString path,IMAGE_FOMART format,QChartView *charView ){
    QPixmap p = charView->grab();
    QImage image = p.toImage();
    image.save(path+"/chart.png");
}

void ChartShow::exportImageSlot(){
    QString dirName = QFileDialog::getExistingDirectory(NULL,"caption",".");
    exportImage(dirName,PNG,this->chartView);
}

void ChartShow::reDraw(){
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
    QChart * oldChart = this->chart;
    this->chart = drawBar(barSetNames,datas,"title1",categorys);
    this->chartView->setChart(this->chart);
    delete  oldChart;
}

void ChartShow::draw(){
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
    this->chart = drawBar(barSetNames,datas,"title",categorys);
    this->chartView->setChart(this->chart);
}

