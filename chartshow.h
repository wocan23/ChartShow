#ifndef CHARTSHOW_H
#define CHARTSHOW_H

#include <QChartView>
#include <QWidget>
#include <QStringList>
#include <QtCharts>
using namespace::QtCharts;


enum IMAGE_FOMART{PNG};

class ChartShow : public QWidget
{
    Q_OBJECT
public:
    explicit ChartShow(QWidget *parent = nullptr);

    QChartView* drawBar(QStringList barSet, double**data,QString title, QStringList categorys);

    void exportImage(QString path,IMAGE_FOMART format,QChartView *chartView );

signals:

public slots:
    void exportImageSlot();
private:
    QChartView * chartView;
};

#endif // CHARTSHOW_H
