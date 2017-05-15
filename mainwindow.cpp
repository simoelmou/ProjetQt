#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    //Connection des bouttons de modification et suppression de patients dans table view
    connect(ui->patientsTableView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(edit_delete_patient_slot(const QModelIndex&)));

    //Status bar
    if(dbManager.Is_Connected())
    {
        register_message("Database is connected.");
    }
    else
    {
        register_message("Database is not connected.");
    }

    //Initialization treeview model
    personnelTreeModel = new PersonnelTreeModel(dbManager.GetAll_Ressource(),this);
    ui->personnelTreeView->setModel(personnelTreeModel);

    //Initialization tableview model
    patienTableModel = new PatientTableModel(dbManager.GetAll_Patient(), this);
    ui->patientsTableView->setModel(patienTableModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuitter_triggered()
{
    close();
}

void MainWindow::on_actionA_propos_triggered()
{
    AboutDialog about(this);
    about.exec();
}

void MainWindow::on_actionPatient_triggered()
{
    AjouterPatientDialog patient(this);
    if(patient.exec() == QDialog::Accepted)
    {
        //Set the new data
        patienTableModel->setPatients(dbManager.GetAll_Patient());

        //Notify the user
        register_message("Patient est ajouté");
    }
}

void MainWindow::on_actionPersonnel_triggered()
{
    AjoutPersonnelDialog personnel(this);
    if(personnel.exec() == QDialog::Accepted)
    {
        //Update the tree model
        personnelTreeModel->setRessources(dbManager.GetAll_Ressource());

        //Notify the user
        register_message("Ressource est ajouté");
    }
}

void MainWindow::on_actionToolbarAjouter_patient_triggered()
{
    AjouterPatientDialog patient(this);
    if(patient.exec() == QDialog::Accepted)
    {
        //Set the new data
        patienTableModel->setPatients(dbManager.GetAll_Patient());

        //Notify the user
        register_message("Patient est ajouté");
    }
}

void MainWindow::on_actionToolbarAjouter_personnel_de_soins_triggered()
{
    AjoutPersonnelDialog personnel(this);
    if(personnel.exec() == QDialog::Accepted)
    {
        //Update the tree model
        personnelTreeModel->setRessources(dbManager.GetAll_Ressource());

        //Notify the user
        register_message("Ressource est ajouté");
    }
}

void MainWindow::on_rechercherPatientButton_clicked()
{
    QString nom = ui->nomRechercherEdit->text();
    QString prenom = ui->prenomRechercherEdit->text();
    QString numeroId = ui->numeroRechercherEdit->text();
    QDate dateDebut = ui->dateDebutRechercherEdit->date();
    QDate dateFin = ui->dateFinRechercherEdit->date();
    //if every field is empty get all the patients
    if(nom.isEmpty() && prenom.isEmpty() && numeroId.isEmpty() &&
            ui->enableDateDebutCheckBox->checkState() == Qt::Unchecked && ui->enableDateFinCheckBox->checkState() == Qt::Unchecked)
    {
        patienTableModel->setPatients(dbManager.GetAll_Patient());
        return;
    }
    //If the first date and last date are selected
    if(ui->enableDateDebutCheckBox->checkState() == Qt::Checked && ui->enableDateFinCheckBox->checkState()  == Qt::Checked)
    {
        patienTableModel->setPatients(dbManager.FindByIdNomPrenomDateDebutDateFin_Patient(numeroId.toInt(), nom, prenom, dateDebut, dateFin));
    }

    //If the first date is selected
    else if(ui->enableDateDebutCheckBox->checkState() == Qt::Checked)
    {
        patienTableModel->setPatients(dbManager.FindByIdNomPrenomDateDebut_Patient(numeroId.toInt(), nom, prenom, dateDebut));
    }

    //If the last date is selected
    else if(ui->enableDateFinCheckBox->checkState()  == Qt::Checked)
    {
        patienTableModel->setPatients(dbManager.FindByIdNomPrenomDateFin_Patient(numeroId.toInt(), nom, prenom, dateFin));
    }
    else
    {
        patienTableModel->setPatients(dbManager.FindByIdNomPrenom_Patient(numeroId.toInt(), nom, prenom));
    }
}

void MainWindow::on_enableDateDebutCheckBox_toggled(bool checked)
{
    ui->dateDebutRechercherEdit->setEnabled(checked);
}

void MainWindow::on_enableDateFinCheckBox_toggled(bool checked)
{
    ui->dateFinRechercherEdit->setEnabled(checked);
}

void MainWindow::on_modifierRessourceButton_clicked()
{
    QModelIndexList indexes = ui->personnelTreeView->selectionModel()->selectedIndexes();
    if (indexes.size() > 0) {
        QModelIndex selectedIndex = indexes.at(0);
        Ressource* ressource = personnelTreeModel->getRessource(selectedIndex);
        if(ressource != NULL)
        {
            AjoutPersonnelDialog dialog(ressource);
            if(dialog.exec() == QDialog::Accepted)
            {
                //Update the treeview
                delete personnelTreeModel;
                personnelTreeModel = new PersonnelTreeModel(dbManager.GetAll_Ressource(),this);
                ui->personnelTreeView->setModel(personnelTreeModel);

                //Notify the user
                register_message("Ressource est modifiée");
            }
        }
    }
}

void MainWindow::on_supprimerRessourceButton_clicked()
{
    QModelIndexList indexes = ui->personnelTreeView->selectionModel()->selectedIndexes();
    if (indexes.size() > 0) {
        QModelIndex selectedIndex = indexes.at(0);
        Ressource* ressource = personnelTreeModel->getRessource(selectedIndex);
        if(ressource != NULL)
        {
            //Supprimer la ressource
            dbManager.Delete_Ressource(ressource->getId());

            //Mise à jour de treeview
            delete personnelTreeModel;
            personnelTreeModel = new PersonnelTreeModel(dbManager.GetAll_Ressource(),this);
            ui->personnelTreeView->setModel(personnelTreeModel);

            //Notify the user
            register_message("Ressource est supprimée");
        }
    }
}

void MainWindow::on_planifierButton_clicked()
{
    QMessageBox::information(this, "Info", "Not yet available !");
}

void MainWindow::edit_delete_patient_slot(const QModelIndex &index)
{
    switch(index.column())
    {
    case 4:
        {
            QString nom = patienTableModel->data(index.row(), 0).toString();
            //Call the dialog to modify the patient
            Patient* currentPatient = patienTableModel->getPatients().at(index.row());
            AjouterPatientDialog dialog(currentPatient);
            if(dialog.exec() == QDialog::Accepted)
            {
                //Sets the new data
                patienTableModel->setPatients(dbManager.GetAll_Patient());

                //Notify the user
                register_message(nom + " est modifié");
            }
        }
        break;
    case 5:
        {
            QString nom = patienTableModel->data(index.row(), 0).toString();

            //Get the selected patient ID
            int idPatient = patienTableModel->getPatients().at(index.row())->getId();

            //Deletes the patients
            dbManager.Delete_Patient(idPatient);

            //Sets the new data
            patienTableModel->setPatients(dbManager.GetAll_Patient());

            //Notify the user
            register_message(nom + " est supprimé");
        }
        break;
    }
}

void MainWindow::register_message(const QString message, int timeout)
{
    statusBar()->showMessage(message, timeout);
}
