#include "charthtextdocument.h"

#include <QPainter>
#include <QTextDocument>

ChartHTextDocument::ChartHTextDocument(QPlainTextEdit *parent) : QPlainTextEdit(parent)
{

}

void ChartHTextDocument::paintEvent(QPaintEvent *e){
    QPainter painter(this->viewport());
    painter.setPen(Qt::blue);

    QRectF rectf(12,12,120,120);

    QTextDocument *document = this->document();
    painter.drawText(10,20,"{...}");

    document->drawContents(&painter,rectf);
    QAbstractTextDocumentLayout::PaintContext paintContext;
    document->documentLayout()->draw(&painter,paintContext);

    this->setDocument(document);

}
