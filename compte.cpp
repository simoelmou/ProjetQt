#include "compte.h"

Compte::Compte()
{}

Compte::Compte(int id, int ressource, const string& login, const string& mdp)
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
    return resource;
}

void Compte::setRessource(int value)
{
    resource = value;
}

string Compte::getLogin() const
{
    return login;
}

void Compte::setLogin(const string &value)
{
    login = value;
}

string Compte::getMdp() const
{
    return mdp;
}

void Compte::setMdp(const string &value)
{
    mdp = value;
}
