#ifndef AJOUTPERSONNELDIALOG_H
#define AJOUTPERSONNELDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "dbmanager.h"

namespace Ui {
class AjoutPersonnelDialog;
}

class AjoutPersonnelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutPersonnelDialog(Ressource* ressource, QWidget *parent = 0);
    explicit AjoutPersonnelDialog(QWidget *parent = 0);
    ~AjoutPersonnelDialog();

private slots:
    //Slot for the button sauvegarder
    void on_sauvegarderButton_clicked();

    //Slot for the button annuler
    void on_annulerButton_clicked();

    //Slot to activate the login and password edit boxes
    void on_infoEdit_toggled(bool checked);

private:
    Ui::AjoutPersonnelDialog *ui;
    bool toUpdate;
    Ressource *currentRessource;
    DBManager dbManager;

    //Initialize the fields with personnel data
    void init();

    //Returns if the data presented by the user is valid or not
    bool isDataValid(const QString& nom, const QString& prenom, int type, const QString& login, const QString& mdp);

};

#endif // AJOUTPERSONNELDIALOG_H
