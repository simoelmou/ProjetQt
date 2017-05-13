#ifndef AJOUTERPATIENTDIALOG_H
#define AJOUTERPATIENTDIALOG_H

#include <QDialog>
#include <QStringListModel>

#include "model/patient.h"
#include "data/dbmanager.h"

namespace Ui {
class AjouterPatientDialog;
}

class AjouterPatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterPatientDialog(QWidget *parent = 0);
    ~AjouterPatientDialog();

private slots:
    void on_ajouterPatientButton_clicked();
    void on_annulerButton_clicked();

private:
    Ui::AjouterPatientDialog *ui;
};

#endif // AJOUTERPATIENTDIALOG_H
