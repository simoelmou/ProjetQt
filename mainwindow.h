#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "aboutdialog.h"
#include "ajouterpatientdialog.h"
#include "patienttablemodel.h"
#include "ajoutpersonneldialog.h"
#include "personneltreemodel.h"
#include "c_init_bd.h"
#include "dbmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void register_message(QString message, int timeout = 4000);

private slots:
    void on_actionQuitter_triggered();
    void on_actionA_propos_triggered();
    void on_actionPatient_triggered();
    void on_actionPersonnel_triggered();
    void on_actionToolbarAjouter_patient_triggered();
    void on_actionToolbarAjouter_personnel_de_soins_triggered();
    void on_rechercherPatientButton_clicked();
    void on_enableDateDebutCheckBox_toggled(bool checked);
    void on_enableDateFinCheckBox_toggled(bool checked);
    void edit_delete_patient_slot(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    PatientTableModel *patienTableModel;
    DBManager dbManager;
};

#endif // MAINWINDOW_H
