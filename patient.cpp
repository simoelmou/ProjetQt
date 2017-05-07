#include "patient.h"

QString Patient::getNom() const
{
    return nom;
}

void Patient::setNom(const QString &value)
{
    nom = value;
}

QString Patient::getPrenom() const
{
    return prenom;
}

void Patient::setPrenom(const QString &value)
{
    prenom = value;
}

QString Patient::getAdresse() const
{
    return adresse;
}

void Patient::setAdresse(const QString &value)
{
    adresse = value;
}

QString Patient::getVille() const
{
    return ville;
}

void Patient::setVille(const QString &value)
{
    ville = value;
}

QString Patient::getCommentaires() const
{
    return commentaires;
}

void Patient::setCommentaires(const QString &value)
{
    commentaires = value;
}

int Patient::getTelephone() const
{
    return telephone;
}

void Patient::setTelephone(int value)
{
    telephone = value;
}

int Patient::getCodePostal() const
{
    return codePostal;
}

void Patient::setCodePostal(int value)
{
    codePostal = value;
}

int Patient::getDureeConsultation() const
{
    return dureeConsultation;
}

void Patient::setDureeConsultation(int value)
{
    dureeConsultation = value;
}

int Patient::getPriorite() const
{
    return priorite;
}

void Patient::setPriorite(int value)
{
    priorite = value;
}

QDate Patient::getDateConsultation() const
{
    return dateConsultation;
}

void Patient::setDateConsultation(const QDate &value)
{
    dateConsultation = value;
}

int Patient::getId() const
{
    return id;
}

void Patient::setId(int value)
{
    id = value;
}

Patient::Patient()
{}

Patient::Patient(int id, QString nom, QString prenom, QString adresse, QString ville,
                 QString commentaires, int tel, int code, QDate date, int duree, int priorite) {

    (*this).id = id;
    (*this).nom = nom;
    (*this).prenom = prenom;
    (*this).adresse = adresse;
    (*this).ville = ville;
    (*this).commentaires = commentaires;
    (*this).telephone = tel;
    (*this).codePostal = code;
    (*this).dateConsultation = date;
    (*this).dureeConsultation = duree;
    (*this).priorite = priorite;
}
