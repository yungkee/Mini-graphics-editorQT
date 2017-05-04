#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* MyApplication = new MainWindow;
    MyApplication->show();

    return a.exec();
}
