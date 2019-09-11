#ifndef CHARTDATA_H
#define CHARTDATA_H

#include <QList>
#include <QStringList>

enum ChartType{
    BAR,PIE,LINE,SCATTER
};

class ChartData
{
public:
    ChartData();
/**
            x轴刻度表   种类名称   二维值   一维值
   条形图：    *           *        *
   扇形图：                *                *
   折线图：    *           *        *
   散点图：                         *
  */
private:
    // 二维值
   QList<QList<double>> data2;
   // x轴刻度名称
   QStringList xScaleNames;
   // 每个值对应分类
   QStringList categories;
   // 一维值
   QList<double> data1;

   // 图类型
   ChartType chartType;

public:
   void setBarData(QStringList xScaleNames, QStringList categories, QList<QList<double>> data2);
   void setPieData(QStringList categories, QList<double> data1);
   void setLineData(QStringList xScaleNames, QStringList categories, QList<QList<double>> data2);
   void setScatterData(QList<QList<double>> data2);

   QList<QList<double>> getData2();
   QStringList getXScalteNames();
   QStringList getCategories();
   QList<double> getData1();
   ChartType getChartType();
};

#endif // CHARTDATA_H
