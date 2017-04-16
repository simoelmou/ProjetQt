#ifndef PATIENT_H
#define PATIENT_H

#include <vector>
#include <iostream>

using namespace std;

class Patient
{
private:
    string nom;
    string prenom;
    string adresse;
    string ville;
    string commentaires;
    int telephone;
    int codePostal;
    int dureeConsultation;
    int priorite;
    vector<int> resources;

public:
    Patient();
    Patient(string nom, string prenom, string adresse, string ville, string commentaires, int tel, int code, int duree, int priorite);

    string getNom() const;
    void setNom(const string &value);
    string getPrenom() const;
    void setPrenom(const string &value);
    string getAdresse() const;
    void setAdresse(const string &value);
    string getVille() const;
    void setVille(const string &value);
    string getCommentaires() const;
    void setCommentaires(const string &value);
    int getTelephone() const;
    void setTelephone(int value);
    int getCodePostal() const;
    void setCodePostal(int value);
    int getDureeConsultation() const;
    void setDureeConsultation(int value);
    int getPriorite() const;
    void setPriorite(int value);
    vector<int> getResources() const;
    void setResources(const vector<int> &value);

    void addResource(int n);
};

#endif // PATIENT_H
