#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QFile>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>

#include "patient.h"
#include "compte.h"
#include "ressource.h"
#include "consultation.h"
#include "type.h"

class DBManager
{
private:
    QSqlDatabase db;

public:
    DBManager();

    //Returns id it's connected to the database
    bool Is_Connected();

    //Inserts patient
    int Insert_Patient(const Patient &patient);

    //Inserts compte
    bool Insert_Compte(const Compte &compte);

    //Inserts ressource
    int Insert_Ressource(const Ressource &ressource);

    //Inserts consultation
    bool Insert_Consultation(const Consultation &consultation);

    //Inserts type
    bool Insert_Type(const Type &type);

    //Finds a patient by its ID
    Patient *Find_Patient(int id);

    //Finds a compte by the ressource ID
    Compte *Find_CompteByRessource(int idRessource);

    //Find a ressource by its ID
    Ressource *Find_Ressource(int id);

    //Finds a consultation by its ID
    Consultation *Find_Consultation(int id);

    //Finds a type by its ID
    Type *Find_Type(int id);

    //Finds a type by its label
    Type *Find_Type(const QString& label);

    //Finds patients by ID, Nom, Prenom, Datedebut and DateFin
    QList<Patient *> FindByIdNomPrenomDateDebutDateFin_Patient(int identification, const QString& nom, const QString& prenom, const QDate& debut, const QDate& fin);

    //Finds patients by ID, Nom, Prenom, Datedebut
    QList<Patient *> FindByIdNomPrenomDateDebut_Patient(int identification, const QString& nom, const QString& prenom, const QDate& debut);

    //Finds patients by ID, Nom, Prenom and DateFin
    QList<Patient *> FindByIdNomPrenomDateFin_Patient(int identification, const QString& nom, const QString& prenom, const QDate& fin);

    //Finds patients by ID, Nom, Prenom
    QList<Patient *> FindByIdNomPrenom_Patient(int identification, const QString& nom, const QString& prenom);

    //Deletes a patient
    bool Delete_Patient(int id);

    //Deletes a compte
    bool Delete_Compte(int id);

    //Deletes compte by its ressource ID
    bool Delete_CompteByRessource(int idRessource);

    //Deletes a ressource
    bool Delete_Ressource(int id);

    //Deletes consultation
    bool Delete_Consultation(int id);

    //Deletes consultation by its patient ID
    bool Delete_ConsultationByPatient(int idPatient);

    //Deletes a type by its ID
    bool Delete_Type(int id);

    //Gets all patients
    QList<Patient *> GetAll_Patient();

    //Gets all comptes
    QList<Compte *> GetAll_Compte();

    //Gets all ressources
    QList<Ressource *> GetAll_Ressource();

    //Gets all consultations
    QList<Consultation *> GetAll_Consultation();

    //Gets all types
    QList<Type *> GetAll_Type();

    //Updates a patient
    bool Update_Patient(const Patient &patient);

    //Updates a ressource
    bool Update_Ressource(const Ressource &ressource);

    //Returns if a user exists in the database
    bool Login_Compte(QString login, QString mdp);
};

#endif // DBMANAGER_H
