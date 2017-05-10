#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    PersonnelTreeModel *treeModel = new PersonnelTreeModel(this);
    ui->personnelTreeView->setModel(treeModel);

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
    personnel.exec();
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
    personnel.exec();
}

void MainWindow::on_rechercherPatientButton_clicked()
{
    QString nom = ui->nomRechercherEdit->text();
    QString prenom = ui->prenomRechercherEdit->text();
    QString numeroId = ui->numeroRechercherEdit->text();
    QDate dateDebut = ui->dateDebutRechercherEdit->date();
    QDate dateFin = ui->dateFinRechercherEdit->date();
    if(nom.isEmpty() && prenom.isEmpty() && numeroId.isEmpty() &&
            ui->enableDateDebutCheckBox->checkState() == Qt::Unchecked && ui->enableDateFinCheckBox->checkState() == Qt::Unchecked)
    {
        patienTableModel->setPatients(dbManager.GetAll_Patient());
        return;
    }

    if(ui->enableDateDebutCheckBox->checkState() == Qt::Checked && ui->enableDateFinCheckBox->checkState()  == Qt::Checked)
    {
        patienTableModel->setPatients(dbManager.FindByIdNomPrenomDateDebutDateFin_Patient(numeroId.toInt(), nom, prenom, dateDebut, dateFin));
    }
    else if(ui->enableDateDebutCheckBox->checkState() == Qt::Checked)
    {
        patienTableModel->setPatients(dbManager.FindByIdNomPrenomDateDebut_Patient(numeroId.toInt(), nom, prenom, dateDebut));
    }
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

void MainWindow::edit_delete_patient_slot(const QModelIndex &index)
{
    switch(index.column())
    {
    case 4:
        register_message("modifier " + patienTableModel->data(index.row(), 0).toString());
        //TODO: modify this patient
        break;
    case 5:
        register_message("supprimer " + patienTableModel->data(index.row(), 0).toString());
        //TODO: delete this patient
        break;
    }
}

void MainWindow::register_message(const QString message, int timeout)
{
    statusBar()->showMessage(message, timeout);
}
