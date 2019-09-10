#ifndef CHARTSHOW_H
#define CHARTSHOW_H

#include <QWidget>
#include <QStringList>
#include <QtCharts>
using namespace QtCharts;
#include <QChartView>

class ChartShow : public QWidget
{
    Q_OBJECT
public:
    explicit ChartShow(QWidget *parent = nullptr);

    QChartView* drawBar(QStringList barSet, double**data,QString title, QStringList categorys);
signals:

public slots:
};

#endif // CHARTSHOW_H
