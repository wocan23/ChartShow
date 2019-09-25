#include "sqlitedboperator.h"

#include <QSqlQuery>

template<class T> SqliteDbOperator<T>::SqliteDbOperator()
{

}

template<class T>QSqlDatabase SqliteDbOperator<T>::openDb(QString dbName){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE",dbName);
    db.open();
    return db;
}

template<class T> QList<T> SqliteDbOperator<T>::query(QList<T>(*fullFunc)(QSqlQuery*)){
//    template<class T> QList<T> SqliteDbOperator<T>::query(QSqlDatabase db, QString sql, QList<QVariant> params, QList<T>(*fullFunc)(QSqlQuery*)){
//    QSqlQuery query(db);
//    bool exec = query.exec(sql);
//    for (int i = 0; i < params.size(); ++i) {
//        query.bindValue(i,params[i]);
//    }
//    if(!exec){
//       return nullptr;
//    }
    return fullFunc(&query);
}
