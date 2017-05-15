#include "ajoutpersonneldialog.h"
#include "ui_ajoutpersonneldialog.h"

#include <iostream>

AjoutPersonnelDialog::AjoutPersonnelDialog(Ressource *ressource, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutPersonnelDialog)
{
    ui->setupUi(this);

    //Sets the curret ressource to be updated
    this->currentRessource = ressource;
    toUpdate = true;
    init();
}

AjoutPersonnelDialog::AjoutPersonnelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutPersonnelDialog)
{
    ui->setupUi(this);

    this->currentRessource = NULL;
    toUpdate = false;
}

AjoutPersonnelDialog::~AjoutPersonnelDialog()
{
    delete ui;
}

void AjoutPersonnelDialog::on_sauvegarderButton_clicked()
{
    QString nom = ui->nomEdit->text();
    QString prenom = ui->prenomEdit->text();
    QString login = ui->loginEdit->text();
    QString pass = ui->passEdit->text();
    bool isInformaticien = false;
    int typeIndex;
    QString typeValue;
    if(ui->medecinAEdit->isChecked())
    {
        typeIndex = 1;
        typeValue = "Médecin A";
    } else if(ui->medecinBEdit->isChecked())
    {
        typeIndex = 2;
        typeValue = "Médecin B";
    } else if(ui->radiologueEdit->isChecked())
    {
        typeIndex = 3;
        typeValue = "Radiologue";
    } else if(ui->infirmiereEdit->isChecked())
    {
        typeIndex = 4;
        typeValue = "Infirmière";
    } else if(ui->kineEdit->isChecked())
    {
        typeIndex = 5;
        typeValue = "Kinésithérapeute";
    } else if(ui->psychEdit->isChecked())
    {
        typeIndex = 6;
        typeValue = "Psychologue";
    } else if(ui->infoEdit->isChecked())
    {
        typeIndex = 7;
        typeValue = "Informaticien";
        isInformaticien = true;
    }
    if(isDataValid(nom, prenom, typeIndex, login, pass)) //If the data is valid
    {
        //Search for the selected type to get its ID
        Type* type = dbManager.Find_Type(typeValue);
        if(type != NULL)
        {
            //Construct the ressource
            Ressource ressource(0, nom, prenom, type->getId());

            //If the user asks the ressource to be updated
            if(toUpdate && this->currentRessource != NULL)
            {
                //Id the ressource is of type : "Informaticien"
                if(this->currentRessource->getType() == 7)
                {
                    //Delete the old "compte"
                    dbManager.Delete_CompteByRessource(this->currentRessource->getId());
                }

                ressource.setId(this->currentRessource->getId());

                //Modifier la ressource
                dbManager.Update_Ressource(ressource);

                if(isInformaticien)
                {
                    //Insertion de compte
                    Compte compte(0, ressource.getId(), login, pass);
                    dbManager.Insert_Compte(compte);
                }
            }
            else
            {
                //Inserts the ressource
                int idRessource = dbManager.Insert_Ressource(ressource);

                //If its "Informaticien" Insert compte
                if(isInformaticien)
                {
                    Compte compte(0, idRessource, login, pass);
                    dbManager.Insert_Compte(compte);
                }
            }

            //Accepts it's destiny and closes the window
            accept();
        }
        else
        {
            //Show a warning to the user
            QMessageBox::warning(this, "Erreur", "Type non trouvé!");
        }
    }
    else
    {
        //Show a warning to the user because of invalid data
        QMessageBox::warning(this, "Erreur", "Il faut remplir : nom, prenom et si Informaticien est coché aussi login, mot de passe !");
    }
}

void AjoutPersonnelDialog::on_annulerButton_clicked()
{
    reject();
}

void AjoutPersonnelDialog::on_infoEdit_toggled(bool checked)
{
    //Enable or disable the login and password edit boxes based on "Informaticien" radio button
    ui->loginEdit->setEnabled(checked);
    ui->passEdit->setEnabled(checked);
}

void AjoutPersonnelDialog::init()
{
    //Fill the fields with the current ressource data
    if(toUpdate && this->currentRessource != NULL)
    {
        ui->nomEdit->setText(currentRessource->getNom());
        ui->prenomEdit->setText(currentRessource->getPrenom());
        switch(currentRessource->getType())
        {
        case 1:
            ui->medecinAEdit->setChecked(true);
            break;
        case 2:
            ui->medecinBEdit->setChecked(true);
            break;
        case 3:
            ui->radiologueEdit->setChecked(true);
            break;
        case 4:
            ui->infirmiereEdit->setChecked(true);
            break;
        case 5:
            ui->kineEdit->setChecked(true);
            break;
        case 6:
            ui->psychEdit->setChecked(true);
            break;
        case 7:
            ui->infoEdit->setChecked(true);
            Compte* compte = dbManager.Find_CompteByRessource(currentRessource->getId());
            ui->loginEdit->setText(compte->getLogin());
            ui->passEdit->setText(compte->getMdp());
            break;
        }
    }
}

bool AjoutPersonnelDialog::isDataValid(const QString &nom, const QString &prenom, int type, const QString &login, const QString &mdp)
{
    return !nom.isEmpty() && !prenom.isEmpty() && (type != 7 || (type == 7 && !login.isEmpty() && !mdp.isEmpty()));
}
