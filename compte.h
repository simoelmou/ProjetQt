#ifndef COMPTE_H
#define COMPTE_H

#include <iostream>

using namespace std;

class Compte
{
public:
    Compte();
    Compte(int id, int ressource, const string& login, const string& mdp);

    int getId() const;
    void setId(int value);

    int getRessource() const;
    void setRessource(int value);

    string getLogin() const;
    void setLogin(const string &value);

    string getMdp() const;
    void setMdp(const string &value);

private:
    int id;
    int ressource;
    string login;
    string mdp;
};

#endif // COMPTE_H
