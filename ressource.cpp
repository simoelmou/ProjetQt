#include "ressource.h"

Ressource::Ressource()
{}

Ressource::Ressource(int id, string nom, string prenom, string type)
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

string Ressource::getNom() const
{
    return nom;
}

void Ressource::setNom(const string &value)
{
    nom = value;
}

string Ressource::getPrenom() const
{
    return prenom;
}

void Ressource::setPrenom(const string &value)
{
    prenom = value;
}

string Ressource::getType() const
{
    return type;
}

void Ressource::setType(const string &value)
{
    type = value;
}
