#include "patient.h"

void Patient::setResources(const vector<int> &value)
{
    resources = value;
}

string Patient::getNom() const
{
    return nom;
}

void Patient::setNom(const string &value)
{
    nom = value;
}

string Patient::getPrenom() const
{
    return prenom;
}

void Patient::setPrenom(const string &value)
{
    prenom = value;
}

string Patient::getAdresse() const
{
    return adresse;
}

void Patient::setAdresse(const string &value)
{
    adresse = value;
}

string Patient::getVille() const
{
    return ville;
}

void Patient::setVille(const string &value)
{
    ville = value;
}

string Patient::getCommentaires() const
{
    return commentaires;
}

void Patient::setCommentaires(const string &value)
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

vector<int> Patient::getResources() const
{
    return resources;
}

Patient::Patient()
{

}

Patient::Patient(string nom, string prenom, string adresse, string ville, string commentaires, int tel, int code, int duree, int priorite) {
    (*this).nom = nom;
    (*this).prenom = prenom;
    (*this).adresse = adresse;
    (*this).ville = ville;
    (*this).commentaires = commentaires;
    (*this).telephone = tel;
    (*this).codePostal = code;
    (*this).dureeConsultation = duree;
    (*this).priorite = priorite;
}

void Patient::addResource(int n){
    resources.push_back(n);
}
