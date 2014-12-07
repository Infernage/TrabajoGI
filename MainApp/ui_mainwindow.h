/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QTableView *table;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QLabel *label_7;
    QLineEdit *phoneEdit;
    QLabel *label_6;
    QLineEdit *surnameEdit;
    QLabel *label_5;
    QLineEdit *nameEdit;
    QLabel *label_8;
    QLineEdit *emailEdit;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *searchButton;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(550, 368);
        MainWindow->setMinimumSize(QSize(400, 300));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        table = new QTableView(groupBox);
        table->setObjectName(QStringLiteral("table"));
        table->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_4->addWidget(table);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAutoFillBackground(false);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_7);

        phoneEdit = new QLineEdit(groupBox_2);
        phoneEdit->setObjectName(QStringLiteral("phoneEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, phoneEdit);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        surnameEdit = new QLineEdit(groupBox_2);
        surnameEdit->setObjectName(QStringLiteral("surnameEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, surnameEdit);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        nameEdit = new QLineEdit(groupBox_2);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, nameEdit);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_8);

        emailEdit = new QLineEdit(groupBox_2);
        emailEdit->setObjectName(QStringLiteral("emailEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, emailEdit);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        searchButton = new QPushButton(groupBox_3);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        horizontalLayout->addWidget(searchButton);

        addButton = new QPushButton(groupBox_3);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout->addWidget(addButton);

        deleteButton = new QPushButton(groupBox_3);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout->addWidget(deleteButton);


        verticalLayout_4->addWidget(groupBox_3);


        verticalLayout_3->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Agenda", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Detalles", 0));
        label_7->setText(QApplication::translate("MainWindow", "<b>Tel\303\251fono</b>", 0));
        phoneEdit->setInputMask(QString());
        label_6->setText(QApplication::translate("MainWindow", "<b>Apellidos</b>", 0));
        label_5->setText(QApplication::translate("MainWindow", "<b>Nombre</b>", 0));
        label_8->setText(QApplication::translate("MainWindow", "<b>Email</b>", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Acciones", 0));
        searchButton->setText(QApplication::translate("MainWindow", "Buscar", 0));
        addButton->setText(QApplication::translate("MainWindow", "A\303\261adir", 0));
        deleteButton->setText(QApplication::translate("MainWindow", "Borrar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
