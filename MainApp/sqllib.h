#ifndef SQLLIB_H
#define SQLLIB_H

#include <QObject>
#include <QThread>
#include <QSqlDatabase>
#include <QList>

class SQLWorker : public QObject
{
    Q_OBJECT
public:
    SQLWorker();
    ~SQLWorker();

public slots:
    void executeSelect(QString select);
    void executeUpdateTable(QString query);

signals:
    void getResult(QList<QVariantList*> *result);

private:
    QSqlDatabase db;
};

class SQLLib : public QObject
{
    Q_OBJECT
public:
    SQLLib();
    ~SQLLib();
    void select(QString s);
    void updateInsertDelete(QString q);

public slots:

signals:
    void emitResult(QList<QVariantList*> *result);
    void execSelect(QString sel);
    void execQuery(QString query);

private:
    QThread workerThread;
    SQLWorker *worker;
};

#endif // SQLLIB_H
