#ifndef BAR_CREATER_H
#define BAR_CREATER_H
#include <QList>
#include <QString>
#include <QtCharts>
using namespace QtCharts;

class bar_creater
{
public:
    bar_creater();

    static QChartView* test();

private:
    QList<QString> serials;
};

#endif // BAR_CREATER_H
