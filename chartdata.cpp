#include "chartdata.h"



ChartData::ChartData()
{

}

QList<double> ChartData::getData1(){
    return this->data1;
}

QStringList ChartData::getCategories(){
    return this->categories;
}

QStringList ChartData::getXScalteNames(){
    return this->xScaleNames;
}

QList<QList<double>> ChartData::getData2(){
    return this->data2;
}

ChartType ChartData::getChartType(){
    return this->chartType;
}

void ChartData::setBarData(QStringList xScaleNames, QStringList categories, QList<QList<double> > data2){
    this->data2 = data2;
    this->xScaleNames = xScaleNames;
    this->categories = categories;
    this->chartType = BAR;
}

void ChartData::setPieData(QStringList categories, QList<double> data1){
    this->data1 = data1;
    this->categories = categories;
    this->chartType = PIE;
}

void ChartData::setLineData(QStringList xScaleNames, QStringList categories, QList<QList<double> > data2){
    this->data2 = data2;
    this->xScaleNames = xScaleNames;
    this->categories = categories;
    this->chartType = LINE;
}

void ChartData::setScatterData(QList<QList<double> > data2){
    this->data2 = data2;
    this->chartType = SCATTER;
}



