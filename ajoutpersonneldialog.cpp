#include "ajoutpersonneldialog.h"
#include "ui_ajoutpersonneldialog.h"

AjoutPersonnelDialog::AjoutPersonnelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutPersonnelDialog)
{
    ui->setupUi(this);
}

AjoutPersonnelDialog::~AjoutPersonnelDialog()
{
    delete ui;
}

void AjoutPersonnelDialog::on_sauvegarderButton_clicked()
{
    QString nom = ui->nomEdit->text();
    QString prenom = ui->prenomEdit->text();
    if(ui->infoEdit->isChecked())
    {
        QString login = ui->loginEdit->text();
        QString pass = ui->passEdit->text();
    }
    //TODO: sauvegarder personnel
    accept();
}

void AjoutPersonnelDialog::on_annulerButton_clicked()
{
    reject();
}

void AjoutPersonnelDialog::on_infoEdit_toggled(bool checked)
{
    ui->loginEdit->setEnabled(checked);
    ui->passEdit->setEnabled(checked);
}
