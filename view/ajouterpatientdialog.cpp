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
    ui->ressourcesListView->setModel(model);
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
    QDate date = ui->dateConsultationEdit->date();
    QString duree = ui->dureeConsultationEdit->text();
    QString commentaires = ui->commentairesEdit->toPlainText();
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
    Patient patient(0, nom, prenom, adresse, ville, commentaires,
                    tel.toInt(), code.toInt(), date, duree.toInt(), priorite);
    //TODO: insert patient in database
    DBManager manager;
    manager.Insert_Patient(patient);
    accept();
}

void AjouterPatientDialog::on_annulerButton_clicked()
{
    reject();
}
