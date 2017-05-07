#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personneltreemodel.h"
#include "c_init_bd.h"
#include "dbmanager.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    //connection des bouttons de modification et suppression de patients dans table view
    connect(ui->patientsTableView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(edit_cell_slot(const QModelIndex&)));

    C_INIT_BD::Creation_BD();

    //Personnel tree view
    PersonnelTreeModel *treeModel = new PersonnelTreeModel(this);
    ui->personnelTreeView->setModel(treeModel);

    //Populating patient table view
    model = new PatientTableModel(this);
    ui->patientsTableView->setModel(model);

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
    patient.exec();
}

void MainWindow::on_actionPersonnel_triggered()
{
    AjoutPersonnelDialog personnel(this);
    personnel.exec();
}

void MainWindow::on_actionToolbarAjouter_patient_triggered()
{
    AjouterPatientDialog patient(this);
    patient.exec();
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
    QString date = ui->dateDebutRechercherEdit->text();
    QString numeroId = ui->numeroRechercherEdit->text();
    //TODO: Search for a patient in the database and repopulate the table model

}

void MainWindow::edit_cell_slot(const QModelIndex &index)
{
    switch(index.column())
    {
    case 4:
        register_message("modifier " + model->data(index.row(), 0).toString());
        //TODO: modify this patient
        break;
    case 5:
        register_message("supprimer " + model->data(index.row(), 0).toString());
        //TODO: delete this patient
        break;
    }
}

void MainWindow::register_message(const QString message)
{
    ui->statusBar->showMessage(message);
}


