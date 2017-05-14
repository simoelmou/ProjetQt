#include "ajouterpatientdialog.h"
#include "ui_ajouterpatientdialog.h"

AjouterPatientDialog::AjouterPatientDialog(Patient *patient, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterPatientDialog)
{
    ui->setupUi(this);

    this->currentPatient = patient;
    toUpdate = true;
    init();

    ressourceListModel = new RessourceListModel(dbManager.GetAll_Ressource(), this);
    ui->ressourcesListView->setModel(ressourceListModel);
}

AjouterPatientDialog::AjouterPatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterPatientDialog)
{
    ui->setupUi(this);

    toUpdate = false;
    ressourceListModel = new RessourceListModel(dbManager.GetAll_Ressource(), this);
    ui->ressourcesListView->setModel(ressourceListModel);
}

AjouterPatientDialog::~AjouterPatientDialog()
{
    delete ui;
}

void AjouterPatientDialog::on_ajouterPatientButton_clicked()
{
    //Nom
    QString nom = ui->nomEdit->text();
    //Prenom
    QString prenom = ui->prenomEdit->text();
    //Adresse
    QString adresse = ui->adresseEdit->text();
    //Ville
    QString ville = ui->villeEdit->text();
    //Tel
    QString tel = ui->telephoneEdit->text();
    //Code postal
    QString code = ui->codePostalEdit->text();
    //Date de consultation
    QDate date = ui->dateConsultationEdit->date();
    //Duree de consultation
    QString duree = ui->dureeConsultationEdit->text();
    //Commentaires
    QString commentaires = ui->commentairesEdit->toPlainText();
    //Priorité
    int priorite = getSelectedPriority();
    //Ressources
    QList<int> ressources;
    foreach (const QModelIndex& index, ui->ressourcesListView->selectionModel()->selectedIndexes()) {
        ressources.append(ressourceListModel->getRessources().at(index.row())->getId());
    }
    //Si les données sont valides
    if(isDataValid(nom, prenom, adresse, ville, code, date, duree, ressources))
    {
        Patient patient(0, nom, prenom, adresse, ville, commentaires,
                        tel.toInt(), code.toInt(), date, duree.toInt(), priorite);

        int idPatient;
        if(toUpdate)
        {
            idPatient = this->currentPatient->getId();
            patient.setId(idPatient);
            //Supprimer les consultations
            dbManager.Delete_ConsultationPatient(idPatient);
            //Modifier patient
            dbManager.Update_Patient(patient);
        }
        else
        {
            // Insertion de patient dans la base de données
            idPatient = dbManager.Insert_Patient(patient);
        }

        //Insertion des ressources dans la base de données
        foreach (int idRessource, ressources) {
            Consultation consul(0, idPatient, idRessource);
            dbManager.Insert_Consultation(consul);
        }
        //Ferme le dialogue
        accept();
    }
    else
    {
        QMessageBox::warning(this, "Erreur", "Il faut remplir : nom, prenom, ville, code postal, date valide, duree et au moins une ressource !");
    }
}

void AjouterPatientDialog::on_annulerButton_clicked()
{
    reject();
}

void AjouterPatientDialog::init()
{
    if(toUpdate)
    {
        ui->nomEdit->setText(this->currentPatient->getNom());
        ui->prenomEdit->setText(this->currentPatient->getPrenom());
        ui->adresseEdit->setText(this->currentPatient->getAdresse());
        ui->villeEdit->setText(this->currentPatient->getVille());
        ui->codePostalEdit->setText(QString::number(this->currentPatient->getCodePostal()));
        ui->dateConsultationEdit->setDate(this->currentPatient->getDateConsultation());
        ui->dureeConsultationEdit->setText(QString::number(this->currentPatient->getDureeConsultation()));
        ui->telephoneEdit->setText(QString::number(this->currentPatient->getTelephone()));
        ui->commentairesEdit->setPlainText(this->currentPatient->getCommentaires());
        switch(this->currentPatient->getPriorite())
        {
        case 1:
            ui->priorite1Radio->setChecked(true);
            break;
        case 2:
            ui->priorite2Radio->setChecked(true);
            break;
        case 3:
            ui->priorite3Radio->setChecked(true);
            break;
        case 4:
            ui->priorite4Radio->setChecked(true);
            break;
        case 5:
            ui->priorite5Radio->setChecked(true);
            break;
        }
    }
}

int AjouterPatientDialog::getSelectedPriority()
{
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
    return priorite;
}

bool AjouterPatientDialog::isDataValid(const QString &nom, const QString &prenom, const QString &adresse,
                                         const QString &ville, const QString &cp, const QDate &dateConsul,
                                         const QString &dureeConsul, QList<int> ressources)
{
    return !nom.isEmpty() && !prenom.isEmpty() && !adresse.isEmpty() && !ville.isEmpty() && !cp.isEmpty() &&
            dateConsul >= QDate::currentDate() && !dureeConsul.isEmpty() && !ressources.isEmpty();
}
