#include "mainwindow.h"
#include <QApplication>

/*!
 * \brief Default main program
 * \param argc
 * \param argv
 * \return exit code
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
