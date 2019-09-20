#ifndef CHARTHTEXTDOCUMENT_H
#define CHARTHTEXTDOCUMENT_H

#include <QWidget>
#include <QPlainTextEdit>

class ChartHTextDocument : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit ChartHTextDocument(QPlainTextEdit *parent = nullptr);

    void paintEvent(QPaintEvent *e);
signals:

public slots:
};

#endif // CHARTHTEXTDOCUMENT_H
