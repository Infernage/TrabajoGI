#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QtSql>

namespace Ui {
class MainWindow;
}

class ActionEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit ActionEdit(QWidget *parent = 0);
    ~ActionEdit();
    QString getHoldText();

protected:
    virtual void focusInEvent(QFocusEvent *e);
    virtual void focusOutEvent(QFocusEvent *e);

private:
    QString holdText;
};

/*!
 * \brief Clase usada para mostrar la ventana principal de la aplicación.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT //! Macro usada para poder definir signals y slots

public:
    /*!
     * \brief Default QObject constructor.
     * \param parent The parent object for this. Default to NULL.
     */
    explicit MainWindow(QWidget *parent = 0);
    /*!
     * Object destructor
     */
    ~MainWindow();

private slots:
    /*!
     * \brief Slot llamado cuando se pulsa el botón buscar.
     */
    bool on_searchButton_clicked(QString phone = QString());

    /*!
     * \brief Slot llamado cuando se pulsa el botón añadir.
     */
    void on_addButton_clicked();

    /*!
     * \brief Slot llamado cuando se pulsa el botón borrar.
     */
    void on_deleteButton_clicked();

private:
    /*!
     * \brief Método usado para mostrar un error.
     * \param error El error SQL a mostrar.
     */
    void showError(const QSqlError &error);
    /*!
     * \brief Método usado para mostrar un error.
     * \param error El error a mostrar.
     */
    void showError(const QString &error);

    Ui::MainWindow *ui; //! GUI components
    QSqlRelationalTableModel *model; //! Modelo relacional con la base de datos.
    ActionEdit *edit;
};

#endif // MAINWINDOW_H
