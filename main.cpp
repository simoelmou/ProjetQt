#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginDialog w;
    if(w.exec() == QDialog::Accepted){
        MainWindow main;
        main.show();
        return a.exec();
    }

    return 0;
}
