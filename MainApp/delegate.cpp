#include "delegate.h"
#include <QDebug>
#include <QMessageBox>

Delegate::Delegate(QObject *parent) :
    QSqlRelationalDelegate(parent)
{}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *line = qobject_cast<QLineEdit*>(editor);
    QString data = line->text();

    int column = index.column();
    bool ok;
    data.toLongLong(&ok);
    if ((!ok || data.size() != 9) && column == 3){
        return;
    }

    for(int i = 0; i < model->rowCount() && column == 3; i++)
    {
        QModelIndex cur = model->index(i,column);
        if(data == model->data(cur, Qt::EditRole).toString() && cur.row() != index.row())
        {
            QMessageBox::critical(editor, "Teléfono repetido", "El teléfono ya existe en un contacto");
            line->setText(model->data(index).toString());
            return;
        }
    }

    model->setData(index, data);
}
