#include "ajouterpatientdialog.h"
#include "ui_ajouterpatientdialog.h"


AjouterPatientDialog::AjouterPatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterPatientDialog)
{
    ui->setupUi(this);
    //TODO: bring resources from database
    QStringList resources;
    resources << "Simo" << "Elmou" << "Wayli";
    QStringListModel *model =new QStringListModel(resources, this);
    ui->resourcesListView->setModel(model);
}

AjouterPatientDialog::~AjouterPatientDialog()
{
    delete ui;
}

void AjouterPatientDialog::on_ajouterPatientButton_clicked()
{
    QString nom = ui->nomEdit->text();
    QString prenom = ui->prenomEdit->text();
    QString adresse = ui->adresseEdit->text();
    QString ville = ui->villeEdit->text();
    QString tel = ui->telephoneEdit->text();
    QString code = ui->codePostalEdit->text();
    QString date = ui->dateConsultationEdit->text();
    QString duree = ui->dureeConsultationEdit->text();
    int priorite = 1;
    if(ui->priorite2Radio->isChecked())
    {
        priorite = 2;
    }
    else if(ui->priorite3Radio->isChecked())
    {
        priorite = 3;
    }
    else if(ui->priorite4Radio->isChecked())
    {
        priorite = 4;
    }
    else if(ui->priorite5Radio->isChecked())
    {
        priorite = 5;
    }
    //TODO: take resources
    QString commentaires = ui->commentairesEdit->toPlainText();
    Patient patient(nom.toStdString(), prenom.toStdString(), adresse.toStdString(),
                    ville.toStdString(), commentaires.toStdString(),
                    tel.toInt(), code.toInt(), duree.toInt(), priorite);
    //TODO: insert patient in database

    accept();
}

void AjouterPatientDialog::on_annulerButton_clicked()
{
    reject();
}
