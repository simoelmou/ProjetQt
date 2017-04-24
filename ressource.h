#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <iostream>

using namespace std;

class Ressource
{
public:
    Ressource();
    Ressource(int id, string nom, string prenom, string type);

    int getId() const;
    void setId(int value);

    string getNom() const;
    void setNom(const string &value);

    string getPrenom() const;
    void setPrenom(const string &value);

    string getType() const;
    void setType(const string &value);

private:
    int id;
    string nom;
    string prenom;
    string type;
};

#endif // RESSOURCE_H
