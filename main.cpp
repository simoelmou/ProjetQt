#include "view/mainwindow.h"
#include "view/logindialog.h"
#include "data/c_init_bd.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Creation base de données
    C_INIT_BD::Create_BD();

    //Création de dialogue de login
    LoginDialog w;

    if(w.exec() == QDialog::Accepted){
        MainWindow main;
        main.show();
        return a.exec();
    }

    C_INIT_BD::Remove_BD();

    return 0;
}
