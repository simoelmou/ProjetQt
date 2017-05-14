#ifndef AJOUTERPATIENTDIALOG_H
#define AJOUTERPATIENTDIALOG_H

#include <QDialog>
#include <QStringListModel>
#include <QMessageBox>

#include "patient.h"
#include "dbmanager.h"
#include "ressourcelistmodel.h"

namespace Ui {
class AjouterPatientDialog;
}

class AjouterPatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterPatientDialog(Patient* patient, QWidget *parent = 0);
    explicit AjouterPatientDialog(QWidget *parent = 0);
    ~AjouterPatientDialog();

private slots:
    void on_ajouterPatientButton_clicked();
    void on_annulerButton_clicked();

private:
    Ui::AjouterPatientDialog *ui;
    RessourceListModel *ressourceListModel;
    bool toUpdate;
    Patient *currentPatient;
    DBManager dbManager;

    void init();
    int getSelectedPriority();
    bool isDataValid(const QString& nom, const QString& prenom, const QString& adresse, const QString& ville,
                       const QString& cp, const QDate& dateConsul, const QString& dureeConsul, QList<int> ressources);
};

#endif // AJOUTERPATIENTDIALOG_H
