#include "sqllib.h"
#include <QDir>
#include <QFile>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

SQLLib::SQLLib()
{
    worker = new SQLWorker;
    worker->moveToThread(&workerThread);
    connect(&workerThread, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(worker, SIGNAL(getResult(QList<QVariantList*>*)), this, SIGNAL(emitResult(QList<QVariantList*>*)));
    connect(this, SIGNAL(execSelect(QString)), worker, SLOT(executeSelect(QString)));
    connect(this, SIGNAL(execQuery(QString)), worker, SLOT(executeUpdateTable(QString)));
    workerThread.start();
}

SQLLib::~SQLLib()
{
    workerThread.quit();
    workerThread.wait();
}

void SQLLib::select(QString s)
{
    emit execSelect(s);
}

void SQLLib::updateInsertDelete(QString q)
{
    emit execQuery(q);
}


SQLWorker::SQLWorker()
{
    db = QSqlDatabase::addDatabase("SQLITE");
    db.setDatabaseName(QCoreApplication::applicationDirPath() + QDir::separator() + "trabajoGI.db");
    if (!db.open()){
        qDebug() << "FAIL";
    }
}

SQLWorker::~SQLWorker()
{
    db.close();
}

void SQLWorker::executeSelect(QString select)
{
    QSqlQuery query(select);
    QList<QVariantList*> *result = new QList<QVariantList*>;
    while(query.next()){
        QVariantList *list = new QVariantList;
        for (int i = 0; i < query.size(); ++i) {
            list->append(query.value(i));
        }
        result->append(list);
    }
    emit getResult(result);
}

void SQLWorker::executeUpdateTable(QString query)
{
    QSqlQuery q;
    q.exec(query);
}
