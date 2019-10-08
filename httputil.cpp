#include "httputil.h"

#include <QUrl>
#include "curl/curl.h"
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QEventLoop>

#include <QDir>
#include <QStringList>
#include <QHttpMultiPart>
#include <QFile>

#include <QNetworkReply>
#include <QHttpPart>


HttpUtil::HttpUtil(QObject *parent) : QObject(parent)
{

}

HttpUtil * HttpUtil::util = new HttpUtil;
HttpUtil * HttpUtil::getInstance(){
    return util;
}

QString HttpUtil::Post(QString url,QString json){
    QNetworkAccessManager _manager;
    QNetworkRequest request = QNetworkRequest(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    QNetworkReply *reply = _manager.post(request, json.toUtf8());
    QByteArray responseData;
    QEventLoop eventLoop;
    connect(&_manager, SIGNAL(finished(QNetworkReply*)), &eventLoop,SLOT(quit()));
    eventLoop.exec();       //block until finish
    responseData = reply->readAll();
    QString result;
    result.prepend(responseData);
    return result;
}

QString HttpUtil::Get(QString url){
    QNetworkAccessManager _manager;
    QNetworkRequest request = QNetworkRequest(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
    QNetworkReply *reply = _manager.get(request);
    QByteArray responseData;
    QEventLoop eventLoop;
    connect(&_manager, SIGNAL(finished(QNetworkReply*)), &eventLoop,SLOT(quit()));
    eventLoop.exec();       //block until finish
    responseData = reply->readAll();
    QString result;
    result.prepend(responseData);
    return result;
}

QString HttpUtil::upload(QString url,QString filePath){

    // 得到文件名称
    QChar sep  = QDir::separator();
    QStringList filePathList = filePath.split(sep);
    QString fileName = filePathList.takeLast();


    QNetworkAccessManager _manager;
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QFile * file = new QFile(filePath);

    file->open(QIODevice::ReadOnly);


    QHttpPart imagePart;
    imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"file\"; filename="+fileName));

    imagePart.setBodyDevice(file);
    file->setParent(multiPart);
    multiPart->append(imagePart);

    QNetworkRequest request = QNetworkRequest(QUrl(url));

    QNetworkReply *reply = _manager.post(request,multiPart);
    reply->setParent(multiPart);
    QByteArray responseData;
    QEventLoop eventLoop;
    connect(&_manager, SIGNAL(finished(QNetworkReply*)), &eventLoop,SLOT(quit()));
    eventLoop.exec();       //block until finish
    responseData = reply->readAll();
    QString result;
    result.prepend(responseData);
    return result;

}

