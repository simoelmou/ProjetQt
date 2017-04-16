#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aboutdialog.h"
#include "ajouterpatientdialog.h"
#include "patienttablemodel.h"
#include "ajoutpersonneldialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQuitter_triggered();
    void on_actionA_propos_triggered();
    void on_actionPatient_triggered();
    void on_actionPersonnel_triggered();
    void on_actionToolbarAjouter_patient_triggered();
    void on_actionToolbarAjouter_personnel_de_soins_triggered();
    void on_rechercherPatientButton_clicked();
    void register_message(QString message);
    void edit_cell_slot(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    PatientTableModel *model;
};

#endif // MAINWINDOW_H
