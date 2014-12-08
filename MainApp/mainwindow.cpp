#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "delegate.h"
#include <QDataWidgetMapper>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); // Inicializa la GUI.
    edit = new ActionEdit(ui->groupBox_3);
    edit->setObjectName(QStringLiteral("phoneActionEdit"));
    ui->horizontalLayout->insertWidget(0, edit);
    edit->setText("Input phone");
    ui->phoneEdit->setInputMask("999999999"); // Añade una máscara al campo de texto del teléfono.
    this->setWindowTitle("Agenda");

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // Carga el driver de la base de datos.
    // Especifica el path a la base de datos.
    db.setDatabaseName(QCoreApplication::applicationDirPath() + "/trabajoGI.db");
    if (!db.open()){ // Abre la base de datos.
        showError(db.lastError());
        return;
    }
    // Crea el modelo relacional.
    model = new QSqlRelationalTableModel(ui->table);
    model->setEditStrategy(QSqlTableModel::OnRowChange); // Especifica la estrategia de edición.
    model->setTable("tContacto"); // Asigna la tabla a relacionar.
    model->setSort(3, Qt::AscendingOrder);

    // Especifica los títulos de la tabla.
    model->setHeaderData(model->fieldIndex("telefono"), Qt::Horizontal, QString("Teléfono"));
    model->setHeaderData(model->fieldIndex("nombre"), Qt::Horizontal, QString("Nombre"));
    model->setHeaderData(model->fieldIndex("apellido"), Qt::Horizontal, QString("Apellidos"));
    model->setHeaderData(model->fieldIndex("email"), Qt::Horizontal, QString("Email"));

    // Obtiene todos los datos almacenados.
    if (!model->select()){
        showError(model->lastError());
        return;
    }

    // Asigna el modelo a la tabla de la GUI.
    ui->table->setModel(model);
    ui->table->setItemDelegate(new Delegate(ui->table));
    // Especifica el tipo de selección.
    ui->table->setSelectionMode(QTableView::SingleSelection);

    // Especifica el mapeo entre los campos de texto de la GUI con el modelo.
    QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->setItemDelegate(new Delegate(this));
    mapper->addMapping(ui->phoneEdit, model->fieldIndex("telefono"));
    mapper->addMapping(ui->nameEdit, model->fieldIndex("nombre"));
    mapper->addMapping(ui->surnameEdit, model->fieldIndex("apellido"));
    mapper->addMapping(ui->emailEdit, model->fieldIndex("email"));

    // Conecta la señal de fila cambiada, con el slot de cambio de índice.
    connect(ui->table->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), mapper,
            SLOT(setCurrentModelIndex(QModelIndex)));
    ui->table->setCurrentIndex(model->index(0, 0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::on_searchButton_clicked(QString phone)
{
    phone = phone.isEmpty() ? edit->getHoldText() : phone;
    if (phone.isEmpty()){
        showError("Teléfono no introducido");
        return false;
    }
    for (int i = 0; i < model->rowCount(); ++i) { // Busca en el modelo el teléfono introducido.
        QModelIndex idx = model->index(i, 3);
        if (phone == model->data(idx).toString()){
            ui->table->selectRow(i);
            ui->table->setFocus();
            return true;
        }
    }
    showError("Contacto no existente");
    return false;
}

void MainWindow::on_addButton_clicked()
{
    QString phone = edit->getHoldText();
    if (phone.isEmpty()){
        showError("Teléfono no introducido");
        return;
    }
    int idx = model->rowCount();
    model->insertRow(idx); // Realiza un insert en la base de datos.
    model->setData(model->index(idx, 3), phone);
    model->setData(model->index(idx, 0), "");
    model->setData(model->index(idx, 1), "");
    model->setData(model->index(idx, 2), "");
    if (!model->submitAll()){ // Realiza un commit.
        showError(QString("Contacto con teléfono \"") + QString::number(idx) + QString("\" ya existente"));
        model->revertAll(); // Realiza un rollback.
        return;
    }
    ui->table->selectRow(idx);
    ui->table->setFocus();
}

void MainWindow::on_deleteButton_clicked()
{
    QString phone = edit->getHoldText();
    if (!phone.isEmpty()){
        if (!on_searchButton_clicked(phone)) return;
    }
    QModelIndexList lst = ui->table->selectionModel()->selectedRows();
    if (lst.count() == 0){
        showError("Contacto no seleccionado");
        return;
    }
    int row = lst.at(0).row();
    model->removeRow(row); // Realiza un delete en la base de datos.
    model->submitAll();
    model->select(); // Refresca la información de la base de datos.
}

void MainWindow::showError(const QSqlError &error)
{
    showError(error.text());
}

void MainWindow::showError(const QString &error)
{
    ui->statusBar->showMessage(error, 2000);
}


ActionEdit::ActionEdit(QWidget *parent) :
    QLineEdit(parent)
{}

ActionEdit::~ActionEdit()
{}

QString ActionEdit::getHoldText()
{
    QString text = holdText;
    holdText.clear();
    return text;
}

void ActionEdit::focusInEvent(QFocusEvent *e)
{
    QLineEdit::focusInEvent(e);
    this->setInputMask("999999999");
    this->setText("000000000");
}

void ActionEdit::focusOutEvent(QFocusEvent *e)
{
    holdText = this->text();
    if (holdText == QString("000000000") || holdText.size() != 9) holdText.clear();
    this->setInputMask("");
    this->setText("Input phone");
    QLineEdit::focusOutEvent(e);
}
