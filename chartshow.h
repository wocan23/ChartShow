#ifndef CHARTSHOW_H
#define CHARTSHOW_H

#include <QChartView>
#include <QWidget>
#include <QStringList>
#include <QtCharts>
#include <QList>
using namespace::QtCharts;
#include <QChart>


enum IMAGE_FOMART{PNG};

class ChartShow : public QWidget
{
    Q_OBJECT
public:
    explicit ChartShow(QWidget *parent = nullptr);

    QChart* drawBar(QStringList barSet, QList<QList<double>> data, QString title, QStringList categorys);

    void exportImage(QString path,IMAGE_FOMART format,QChartView *chartView );

signals:

public slots:
    void exportImageSlot();
    void reDraw();
    void draw();
private:
    QChartView * chartView;
    QChart *chart;
};

#endif // CHARTSHOW_H
