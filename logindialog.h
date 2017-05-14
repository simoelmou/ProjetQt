#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "dbmanager.h"


namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_connectButton_clicked();
    void on_annulerButton_clicked();

private:
    Ui::LoginDialog *ui;
    bool isVerified(QString username, QString password);
};

#endif // LOGINDIALOG_H
