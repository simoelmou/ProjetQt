#include "view/logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent), ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    //QMetaObject::connectSlotsByName(this); if you don't want to do < private slots: >
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_connectButton_clicked()
{
    QString title = "SimoElmou";
    QString usernameString = ui->usernameEdit->text();
    QString passwordString = ui->passwordEdit->text();
    if(isVerified(usernameString, passwordString)){
        accept();
    } else {
        QMessageBox::warning(this, title, "Login ou Mot de passe incorrecte !");
        ui->passwordEdit->setText("");
    }
}

void LoginDialog::on_annulerButton_clicked()
{
    reject();
}

bool LoginDialog::isVerified(QString username, QString password)
{
    DBManager manager;

    return manager.Login_Compte(username, password);
}
