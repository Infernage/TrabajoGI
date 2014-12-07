#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "delegate.h"
#include <QDataWidgetMapper>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->phoneEdit->setInputMask("999-999-999");
    this->setWindowTitle("Agenda");

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QCoreApplication::applicationDirPath() + "/trabajoGI.db");
    if (!db.open()){
        showError(db.lastError());
        return;
    }
    model = new QSqlRelationalTableModel(ui->table);
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    model->setTable("tContacto");
    model->setSort(3, Qt::AscendingOrder);

    model->setHeaderData(model->fieldIndex("telefono"), Qt::Horizontal, QString("Teléfono"));
    model->setHeaderData(model->fieldIndex("nombre"), Qt::Horizontal, QString("Nombre"));
    model->setHeaderData(model->fieldIndex("apellido"), Qt::Horizontal, QString("Apellidos"));
    model->setHeaderData(model->fieldIndex("email"), Qt::Horizontal, QString("Email"));

    if (!model->select()){
        showError(model->lastError());
        return;
    }

    ui->table->setModel(model);
    ui->table->setItemDelegate(new Delegate(ui->table));
    ui->table->setSelectionMode(QTableView::SingleSelection);

    QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->setItemDelegate(new Delegate(this));
    mapper->addMapping(ui->phoneEdit, model->fieldIndex("telefono"));
    mapper->addMapping(ui->nameEdit, model->fieldIndex("nombre"));
    mapper->addMapping(ui->surnameEdit, model->fieldIndex("apellido"));
    mapper->addMapping(ui->emailEdit, model->fieldIndex("email"));

    connect(ui->table->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), mapper,
            SLOT(setCurrentModelIndex(QModelIndex)));
    ui->table->setCurrentIndex(model->index(0, 0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_searchButton_clicked()
{
    if (ui->phoneEdit->text().isEmpty()){
        showError(QLatin1String("Teléfono no introducido"));
        return;
    }
    for (int i = 0; i < model->rowCount(); ++i) {
        QModelIndex idx = model->index(i, 3);
        if (ui->phoneEdit->text().replace("-", "") == model->data(idx).toString()){
            ui->table->selectRow(i);
            return;
        }
    }
    showError("Contacto no existente");
}

void MainWindow::on_addButton_clicked()
{
    int idx = model->rowCount();
    model->insertRow(idx);
    model->setData(model->index(idx, 3), idx);
    model->setData(model->index(idx, 0), "");
    model->setData(model->index(idx, 1), "");
    model->setData(model->index(idx, 2), "");
    if (!model->submitAll()){
        showError(QString("Contacto con teléfono \"") + QString::number(idx) + QString("\" ya existente"));
        model->revertAll();
        return;
    }
    ui->table->selectRow(idx);
}

void MainWindow::on_deleteButton_clicked()
{
    QModelIndexList lst = ui->table->selectionModel()->selectedRows();
    if (lst.count() == 0){
        showError("Contacto no seleccionado");
        return;
    }
    int row = lst.at(0).row();
    model->removeRow(row);
    model->submitAll();
    model->select();
}

void MainWindow::showError(const QSqlError &error)
{
    showError(error.text());
}

void MainWindow::showError(const QString &error)
{
    ui->statusBar->showMessage(error, 2000);
}
