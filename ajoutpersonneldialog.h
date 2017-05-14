#ifndef AJOUTPERSONNELDIALOG_H
#define AJOUTPERSONNELDIALOG_H

#include <QDialog>

namespace Ui {
class AjoutPersonnelDialog;
}

class AjoutPersonnelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutPersonnelDialog(QWidget *parent = 0);
    ~AjoutPersonnelDialog();

private slots:
    void on_sauvegarderButton_clicked();
    void on_annulerButton_clicked();
    void on_infoEdit_toggled(bool checked);

private:
    Ui::AjoutPersonnelDialog *ui;

};

#endif // AJOUTPERSONNELDIALOG_H
