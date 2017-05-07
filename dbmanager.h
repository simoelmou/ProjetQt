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

    bool Insert_Patient(const Patient &patient);
    bool Insert_Compte(const Compte &compte);
    bool Insert_Ressource(const Ressource &ressource);
    bool Insert_Consultation(const Consultation &consultation);
    bool Insert_Type(const Type &type);

    Patient *Find_Patient(int id);
    Compte *Find_Compte(int id);
    Ressource *Find_Ressource(int id);
    Consultation *Find_Consultation(int id);
    Type *Find_Type(int id);

    bool Delete_Patient(int id);
    bool Delete_Compte(int id);
    bool Delete_Ressource(int id);
    bool Delete_Consultation(int id);
    bool Delete_Type(int id);

    QList<Patient *> GetAll_Patient();
    QList<Compte *> GetAll_Compte();
    QList<Ressource *> GetAll_Ressource();
    QList<Consultation *> GetAll_Consultation();
    QList<Type *> GetAll_Type();

    bool Login_Compte(QString login, QString mdp);

};

#endif // DBMANAGER_H
