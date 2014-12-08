#ifndef DELEGATE_H
#define DELEGATE_H

#include <QSqlRelationalDelegate>
#include <QLineEdit>

/*!
 * \brief Clase usada para restringir elementos duplicados en la tabla.
 */
class Delegate : public QSqlRelationalDelegate
{
public:
    /*!
     * \brief Default QObject constructor.
     * \param parent The parent object for this. Default to NULL.
     */
    explicit Delegate(QObject *parent = 0);

protected:
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
};

#endif // DELEGATE_H
