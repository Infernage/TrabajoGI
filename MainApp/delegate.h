#ifndef DELEGATE_H
#define DELEGATE_H

#include <QSqlRelationalDelegate>
#include <QLineEdit>

class Delegate : public QSqlRelationalDelegate
{
public:
    explicit Delegate(QObject *parent = 0);

protected:
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
};

#endif // DELEGATE_H
