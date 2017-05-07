#include "compte.h"

Compte::Compte()
{}

Compte::Compte(int id, int ressource, const QString& login, const QString& mdp)
{
    setId(id);
    setRessource(ressource);
    setLogin(login);
    setMdp(mdp);
}

int Compte::getId() const
{
    return id;
}

void Compte::setId(int value)
{
    id = value;
}

int Compte::getRessource() const
{
    return ressource;
}

void Compte::setRessource(int value)
{
    ressource = value;
}

QString Compte::getLogin() const
{
    return login;
}

void Compte::setLogin(const QString &value)
{
    login = value;
}

QString Compte::getMdp() const
{
    return mdp;
}

void Compte::setMdp(const QString &value)
{
    mdp = value;
}
