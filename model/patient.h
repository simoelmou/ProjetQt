#ifndef PATIENT_H
#define PATIENT_H

#include <vector>
#include <iostream>
#include <QString>
#include <QDate>

class Patient
{
private:
    int id;
    QString nom;
    QString prenom;
    QString adresse;
    QString ville;
    QString commentaires;
    QDate dateConsultation;
    int telephone;
    int codePostal;
    int dureeConsultation;
    int priorite;

public:
    Patient();
    Patient(int id, QString nom, QString prenom, QString adresse, QString ville,
            QString commentaires, int tel, int code, QDate date, int duree, int priorite);

    QString getNom() const;
    void setNom(const QString &value);
    QString getPrenom() const;
    void setPrenom(const QString &value);
    QString getAdresse() const;
    void setAdresse(const QString &value);
    QString getVille() const;
    void setVille(const QString &value);
    QString getCommentaires() const;
    void setCommentaires(const QString &value);
    int getTelephone() const;
    void setTelephone(int value);
    int getCodePostal() const;
    void setCodePostal(int value);
    int getDureeConsultation() const;
    void setDureeConsultation(int value);
    int getPriorite() const;
    void setPriorite(int value);
    QDate getDateConsultation() const;
    void setDateConsultation(const QDate &value);
    int getId() const;
    void setId(int value);
};

#endif // PATIENT_H
