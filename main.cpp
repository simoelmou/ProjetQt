#include "mainwindow.h"
#include "logindialog.h"
#include "c_init_bd.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    C_INIT_BD::Create_BD();

    LoginDialog w;
    if(w.exec() == QDialog::Accepted){
        MainWindow main;
        main.show();
        return a.exec();
    }

    C_INIT_BD::Remove_BD();

    return 0;
}
