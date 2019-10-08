#ifndef HTTPUTIL_H
#define HTTPUTIL_H


#include <QObject>
#include <QString>

class HttpUtil : public QObject
{
    Q_OBJECT
private:
    explicit HttpUtil(QObject *parent = nullptr);
    static HttpUtil * util;
public:
    static QString Post(QString url, QString json);
    static QString Get(QString url);
    static QString upload(QString url, QString filePath);
    static HttpUtil * getInstance();
signals:

public slots:
};

#endif // HTTPUTIL_H
