#include "ressource.h"

Ressource::Ressource()
{}

Ressource::Ressource(int id, QString nom, QString prenom, int type)
{
    setId(id);
    setNom(nom);
    setPrenom(prenom);
    setType(type);
}

int Ressource::getId() const
{
    return id;
}

void Ressource::setId(int value)
{
    id = value;
}

QString Ressource::getNom() const
{
    return nom;
}

void Ressource::setNom(const QString &value)
{
    nom = value;
}

QString Ressource::getPrenom() const
{
    return prenom;
}

void Ressource::setPrenom(const QString &value)
{
    prenom = value;
}

int Ressource::getType() const
{
    return type;
}

void Ressource::setType(int value)
{
    type = value;
}
