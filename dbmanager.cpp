#include "dbmanager.h"

DBManager::DBManager()
{
    db = QSqlDatabase::database("connection-name");
    if(!db.open())
    {
        qDebug() << db.lastError().text();
        qDebug() << "Erreur à louverture de la base !\n";
    }
}

bool DBManager::Is_Connected()
{
    return db.isOpen();
}

int DBManager::Insert_Patient(const Patient& patient)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO TPatient (Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateConsultation, DureeConsultation, Priorite) VALUES (:nom, :prenom, :adresse, :ville, :cp, :commentaire, :tel, :date, :duree, :prio)");
    query.bindValue(":nom", patient.getNom());
    query.bindValue(":prenom", patient.getPrenom());
    query.bindValue(":adresse", patient.getAdresse());
    query.bindValue(":ville", patient.getVille());
    query.bindValue(":cp", patient.getCodePostal());
    query.bindValue(":commentaire", patient.getCommentaires());
    query.bindValue(":tel", patient.getTelephone());
    query.bindValue(":date", patient.getDateConsultation());
    query.bindValue(":duree", patient.getDureeConsultation());
    query.bindValue(":prio", patient.getPriorite());
    int lastId = -1;
    if(!query.exec())
    {
        qDebug() << "Insert_Patient error : " << query.lastError();
    }
    else
    {
        lastId = query.lastInsertId().toInt();
    }
    return lastId;
}

bool DBManager::Insert_Compte(const Compte &compte)
{
    bool success = false;
    // you should check if args are ok first...
    QSqlQuery query(db);
    query.prepare("INSERT INTO TCompte (IdRessource, Login, MdP) VALUES (:ressource, :login, :mdp)");
    query.bindValue(":ressource", compte.getRessource());
    query.bindValue(":login", compte.getLogin());
    query.bindValue(":mdp", compte.getMdp());
    success = query.exec();
    if(!success)
    {
        qDebug() << "Insert_Compte error : " << query.lastError();
    }
    return success;
}

int DBManager::Insert_Ressource(const Ressource &ressource)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO TRessource (Nom, Prenom, IdType) VALUES (:nom, :prenom, :type)");
    query.bindValue(":nom", ressource.getNom());
    query.bindValue(":prenom", ressource.getPrenom());
    query.bindValue(":type", ressource.getType());
    int lastId = -1;
    if(!query.exec())
    {
        qDebug() << "Insert_Ressource error : " << query.lastError();
    }
    else
    {
        lastId = query.lastInsertId().toInt();
    }
    return lastId;
}

bool DBManager::Insert_Consultation(const Consultation &consultation)
{
    bool success = false;
    // you should check if args are ok first...
    QSqlQuery query(db);
    query.prepare("INSERT INTO TConsult (IdPatient, IdRessource) VALUES (:patient, :ressource)");
    query.bindValue(":patient", consultation.getIdPatient());
    query.bindValue(":ressource", consultation.getIdRessource());
    success = query.exec();
    if(!success)
    {
        qDebug() << "Insert_Consultation error : " << query.lastError();
    }
    return success;
}

bool DBManager::Insert_Type(const Type &type)
{
    bool success = false;
    // you should check if args are ok first...
    QSqlQuery query(db);
    query.prepare("INSERT INTO TType (Label) VALUES (:label)");
    query.bindValue(":label", type.getLabel());
    success = query.exec();
    if(!success)
    {
        qDebug() << "Insert_Type error : " << query.lastError();
    }
    return success;
}

Patient* DBManager::Find_Patient(int id)
{
    QSqlQuery query(db);
    query.prepare("SELECT Nom, Prenom, Adresse, Ville, Commentaire, Tel, CP, "
                  "DateConsultation, DureeConsultation, Priorite "
                  "FROM TPatient WHERE Id = :idPatient");
    query.bindValue(":idPatient", id);
    Patient* patient = NULL;
    if(query.exec() && query.next())
    {
        QString nom = query.value(0).toString();
        QString prenom = query.value(1).toString();
        QString adresse = query.value(2).toString();
        QString ville = query.value(3).toString();
        QString commentaire = query.value(4).toString();
        int tel = query.value(5).toInt();
        int cp = query.value(6).toInt();
        QDate date = query.value(7).toDate();
        int duree = query.value(8).toInt();
        int prio = query.value(9).toInt();

        patient = new Patient(id, nom, prenom, adresse, ville, commentaire, tel, cp, date, duree, prio);
    }
    return patient;
}

Compte* DBManager::Find_CompteByRessource(int idRessource)
{
    QSqlQuery query(db);
    query.prepare("SELECT Id, IdRessource, Login, MdP "
                  "FROM TCompte WHERE IdRessource = :idRessource");
    query.bindValue(":idRessource", idRessource);
    Compte* compte = NULL;
    if(query.exec() && query.next())
    {
        int Id = query.value(0).toInt();
        int IdRessource = query.value(1).toInt();
        QString Login = query.value(2).toString();
        QString MdP = query.value(3).toString();

        compte = new Compte(Id, IdRessource, Login, MdP);
    }
    return compte;
}

Ressource *DBManager::Find_Ressource(int id)
{
    QSqlQuery query(db);
    query.prepare("SELECT Nom, Prenom, IdType "
                  "FROM TRessource WHERE Id = :idRessource");
    query.bindValue(":idRessource", id);
    Ressource* ressource = NULL;
    if(query.exec() && query.next())
    {
        QString Nom = query.value(0).toString();
        QString Prenom = query.value(1).toString();
        int IdType = query.value(2).toInt();

        ressource = new Ressource(id, Nom, Prenom, IdType);
    }
    return ressource;
}

Consultation *DBManager::Find_Consultation(int id)
{
    QSqlQuery query(db);
    query.prepare("SELECT IdPatient, IdRessource "
                  "FROM TConsult WHERE Id = :idConsult");
    query.bindValue(":idConsult", id);
    Consultation* consultation = NULL;
    if(query.exec() && query.next())
    {
        int IdPatient = query.value(0).toInt();
        int IdRessource = query.value(1).toInt();

        consultation = new Consultation(id, IdPatient, IdRessource);
    }
    return consultation;
}

Type *DBManager::Find_Type(int id)
{
    QSqlQuery query(db);
    query.prepare("SELECT Label "
                  "FROM TType WHERE Id = :idType");
    query.bindValue(":idType", id);
    Type* type = NULL;
    if(query.exec() && query.next())
    {
        QString label = query.value(0).toString();

        type = new Type(id, label);
    }
    return type;
}

Type *DBManager::Find_Type(const QString &label)
{
    QSqlQuery query(db);
    query.prepare("SELECT Id, Label "
                  "FROM TType WHERE Label = :label");
    query.bindValue(":label", label);
    Type* type = NULL;
    if(query.exec() && query.next())
    {

        int id = query.value(0).toInt();
        QString label = query.value(1).toString();

        type = new Type(id, label);
    }
    return type;
}

QList<Patient *> DBManager::FindByIdNomPrenomDateDebutDateFin_Patient(int identification, const QString &nom, const QString &prenom, const QDate& debut, const QDate& fin)
{
    QList<Patient*> patients;
    QSqlQuery query(db);
    query.prepare("SELECT Id, Nom, Prenom, Adresse, Ville, Commentaire, Tel, CP, "
                      "DateConsultation, DureeConsultation, Priorite "
                      "FROM TPatient WHERE Id=:id OR Nom LIKE :nom OR Prenom LIKE :prenom OR DateConsultation BETWEEN :dateDebut AND :dateFin");
    QString newNom = "";
    QString newPrenom = "";
    if(!nom.isEmpty())
    {
        newNom = nom + '%';
    }if(!prenom.isEmpty())
    {
        newPrenom = prenom + '%';
    }
    query.bindValue(":id", identification);
    query.bindValue(":nom", newNom);
    query.bindValue(":prenom", newPrenom);
    query.bindValue(":dateDebut", debut);
    query.bindValue(":dateFin", fin);
    if(query.exec())
    {
        while(query.next())
        {
            int Id = query.value(0).toInt();
            QString nom = query.value(1).toString();
            QString prenom = query.value(2).toString();
            QString adresse = query.value(3).toString();
            QString ville = query.value(4).toString();
            QString commentaire = query.value(5).toString();
            int cp = query.value(6).toInt();
            int tel = query.value(7).toInt();
            QDate date = query.value(8).toDate();
            int duree = query.value(9).toInt();
            int priorite = query.value(10).toInt();

            Patient* patient = new Patient(Id, nom, prenom, adresse, ville, commentaire, tel, cp, date, duree, priorite);
            patients.append(patient);
        }
    }
    return patients;
}

QList<Patient *> DBManager::FindByIdNomPrenomDateDebut_Patient(int identification, const QString &nom, const QString &prenom, const QDate& debut)
{
    QList<Patient*> patients;
    QSqlQuery query(db);
    query.prepare("SELECT Id, Nom, Prenom, Adresse, Ville, Commentaire, Tel, CP, "
                      "DateConsultation, DureeConsultation, Priorite "
                      "FROM TPatient WHERE Id=:id OR Nom LIKE :nom OR Prenom LIKE :prenom OR DateConsultation >= :dateDebut");
    QString newNom = "";
    QString newPrenom = "";
    if(!nom.isEmpty())
    {
        newNom = nom + '%';
    }if(!prenom.isEmpty())
    {
        newPrenom = prenom + '%';
    }
    query.bindValue(":id", identification);
    query.bindValue(":nom", newNom);
    query.bindValue(":prenom", newPrenom);
    query.bindValue(":dateDebut", debut);
    if(query.exec())
    {
        while(query.next())
        {
            int Id = query.value(0).toInt();
            QString nom = query.value(1).toString();
            QString prenom = query.value(2).toString();
            QString adresse = query.value(3).toString();
            QString ville = query.value(4).toString();
            QString commentaire = query.value(5).toString();
            int cp = query.value(6).toInt();
            int tel = query.value(7).toInt();
            QDate date = query.value(8).toDate();
            int duree = query.value(9).toInt();
            int priorite = query.value(10).toInt();

            Patient* patient = new Patient(Id, nom, prenom, adresse, ville, commentaire, tel, cp, date, duree, priorite);
            patients.append(patient);
        }
    }
    return patients;
}

QList<Patient *> DBManager::FindByIdNomPrenomDateFin_Patient(int identification, const QString &nom, const QString &prenom, const QDate& fin)
{
    QList<Patient*> patients;
    QSqlQuery query(db);
    query.prepare("SELECT Id, Nom, Prenom, Adresse, Ville, Commentaire, Tel, CP, "
                      "DateConsultation, DureeConsultation, Priorite "
                      "FROM TPatient WHERE Id=:id OR Nom LIKE :nom OR Prenom LIKE :prenom OR DateConsultation <= :dateFin");
    QString newNom = "";
    QString newPrenom = "";
    if(!nom.isEmpty())
    {
        newNom = nom + '%';
    }if(!prenom.isEmpty())
    {
        newPrenom = prenom + '%';
    }
    query.bindValue(":id", identification);
    query.bindValue(":nom", newNom);
    query.bindValue(":prenom", newPrenom);
    query.bindValue(":dateFin", fin);
    if(query.exec())
    {
        while(query.next())
        {
            int Id = query.value(0).toInt();
            QString nom = query.value(1).toString();
            QString prenom = query.value(2).toString();
            QString adresse = query.value(3).toString();
            QString ville = query.value(4).toString();
            QString commentaire = query.value(5).toString();
            int cp = query.value(6).toInt();
            int tel = query.value(7).toInt();
            QDate date = query.value(8).toDate();
            int duree = query.value(9).toInt();
            int priorite = query.value(10).toInt();

            Patient* patient = new Patient(Id, nom, prenom, adresse, ville, commentaire, tel, cp, date, duree, priorite);
            patients.append(patient);
        }
    }
    return patients;
}

QList<Patient *> DBManager::FindByIdNomPrenom_Patient(int identification, const QString &nom, const QString &prenom)
{
    QList<Patient*> patients;
    QSqlQuery query(db);
    query.prepare("SELECT Id, Nom, Prenom, Adresse, Ville, Commentaire, Tel, CP, "
                      "DateConsultation, DureeConsultation, Priorite "
                      "FROM TPatient WHERE Id=:id OR Nom LIKE :nom  OR Prenom LIKE :prenom");
    QString newNom = "";
    QString newPrenom = "";
    if(!nom.isEmpty())
    {
        newNom = nom + '%';
    }if(!prenom.isEmpty())
    {
        newPrenom = prenom + '%';
    }
    query.bindValue(":id", identification);
    query.bindValue(":nom", newNom);
    query.bindValue(":prenom", newPrenom);
    if(query.exec())
    {
        while(query.next())
        {
            int Id = query.value(0).toInt();
            QString nom = query.value(1).toString();
            QString prenom = query.value(2).toString();
            QString adresse = query.value(3).toString();
            QString ville = query.value(4).toString();
            QString commentaire = query.value(5).toString();
            int cp = query.value(6).toInt();
            int tel = query.value(7).toInt();
            QDate date = query.value(8).toDate();
            int duree = query.value(9).toInt();
            int priorite = query.value(10).toInt();

            Patient* patient = new Patient(Id, nom, prenom, adresse, ville, commentaire, tel, cp, date, duree, priorite);
            patients.append(patient);
        }
    }
    return patients;
}

bool DBManager::Delete_Patient(int id)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM TPatient "
                  "WHERE Id = :idO");
    query.bindValue(":idO", id);
    return query.exec();
}

bool DBManager::Delete_Compte(int id)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM TCompte "
                  "WHERE Id = :idO");
    query.bindValue(":idO", id);
    return query.exec();
}

bool DBManager::Delete_CompteByRessource(int idRessource)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM TCompte "
                  "WHERE IdRessource = :idO");
    query.bindValue(":idO", idRessource);
    return query.exec();
}

bool DBManager::Delete_Ressource(int id)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM TRessource "
                  "WHERE Id = :idO");
    query.bindValue(":idO", id);
    return query.exec();
}

bool DBManager::Delete_Consultation(int id)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM TConsult "
                  "WHERE Id = :idO");
    query.bindValue(":idO", id);
    return query.exec();
}

bool DBManager::Delete_ConsultationByPatient(int idPatient)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM TConsult "
                  "WHERE IdPatient = :idO");
    query.bindValue(":idO", idPatient);
    return query.exec();
}

bool DBManager::Delete_Type(int id)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM TType "
                  "WHERE Id = :idO");
    query.bindValue(":idO", id);
    return query.exec();
}

QList<Patient*> DBManager::GetAll_Patient()
{
    QList<Patient*> patients;
    QSqlQuery query(db);
    if(query.exec("SELECT Id, Nom, Prenom, Adresse, Ville, Commentaire, Tel, CP, "
                  "DateConsultation, DureeConsultation, Priorite "
                  "FROM TPatient"))
    {
        while(query.next())
        {
            int Id = query.value(0).toInt();
            QString nom = query.value(1).toString();
            QString prenom = query.value(2).toString();
            QString adresse = query.value(3).toString();
            QString ville = query.value(4).toString();
            QString commentaire = query.value(5).toString();
            int cp = query.value(6).toInt();
            int tel = query.value(7).toInt();
            QDate date = query.value(8).toDate();
            int duree = query.value(9).toInt();
            int priorite = query.value(10).toInt();

            Patient* patient = new Patient(Id, nom, prenom, adresse, ville, commentaire, tel, cp, date, duree, priorite);
            patients.append(patient);
        }
    }
    return patients;
}

QList<Compte *> DBManager::GetAll_Compte()
{
    QList<Compte*> comptes;
    QSqlQuery query(db);
    if(query.exec("SELECT Id, IdRessource, Login, MdP FROM TCompte"))
    {
        while(query.next())
        {
            int Id = query.value(0).toInt();
            int IdRessource = query.value(1).toInt();
            QString Login = query.value(2).toString();
            QString MdP = query.value(3).toString();

            Compte* compte = new Compte(Id, IdRessource, Login, MdP);
            comptes.append(compte);
        }
    }
    return comptes;
}

QList<Ressource *> DBManager::GetAll_Ressource()
{
    QList<Ressource*> ressources;
    QSqlQuery query(db);
    if(query.exec("SELECT Id, Nom, Prenom, IdType FROM TRessource"))
    {
        while(query.next())
        {
            int Id = query.value(0).toInt();
            QString Nom = query.value(1).toString();
            QString Prenom = query.value(2).toString();
            int IdType = query.value(3).toInt();

            Ressource* ressource = new Ressource(Id, Nom, Prenom, IdType);
            ressources.append(ressource);
        }
    }
    return ressources;
}

QList<Consultation *> DBManager::GetAll_Consultation()
{
    QList<Consultation*> consultations;
    QSqlQuery query(db);
    if(query.exec("SELECT Id, IdPatient, IdRessource FROM TConsult"))
    {
        while(query.next())
        {
            int Id = query.value(0).toInt();
            int IdPatient = query.value(1).toInt();
            int IdRessource = query.value(2).toInt();

            Consultation* consultation = new Consultation(Id, IdPatient, IdRessource);
            consultations.append(consultation);
        }
    }
    return consultations;
}

QList<Type *> DBManager::GetAll_Type()
{
    QList<Type *> types;
    QSqlQuery query(db);
    if(query.exec("SELECT Id, Label FROM TType"))
    {
        while(query.next())
        {
            int Id = query.value(0).toInt();
            QString label = query.value(1).toString();

            Type* type = new Type(Id, label);
            types.append(type);
        }
    }
    return types;
}

bool DBManager::Update_Patient(const Patient &patient)
{
    bool success;
    QSqlQuery query(db);
    query.prepare("UPDATE TPatient SET Nom=:nom, Prenom=:prenom, Adresse=:adresse, Ville=:ville, CP=:cp, Commentaire=:commentaire, "
                  "Tel=:tel, DateConsultation=:date, DureeConsultation=:duree, Priorite=:prio "
                  "WHERE Id=:idPatient");
    query.bindValue(":idPatient", patient.getId());
    query.bindValue(":nom", patient.getNom());
    query.bindValue(":prenom", patient.getPrenom());
    query.bindValue(":adresse", patient.getAdresse());
    query.bindValue(":ville", patient.getVille());
    query.bindValue(":cp", patient.getCodePostal());
    query.bindValue(":commentaire", patient.getCommentaires());
    query.bindValue(":tel", patient.getTelephone());
    query.bindValue(":date", patient.getDateConsultation());
    query.bindValue(":duree", patient.getDureeConsultation());
    query.bindValue(":prio", patient.getPriorite());
    success = query.exec();
    if(!success)
    {
        qDebug() << "Update_Patient error : " << query.lastError();
    }
    return success;
}

bool DBManager::Update_Ressource(const Ressource &ressource)
{
    bool success;
    QSqlQuery query(db);
    query.prepare("UPDATE TRessource SET Nom=:nom, Prenom=:prenom, IdType=:type WHERE Id=:id");
    query.bindValue(":nom", ressource.getNom());
    query.bindValue(":prenom", ressource.getPrenom());
    query.bindValue(":type", ressource.getType());
    query.bindValue(":id", ressource.getId());
    success = query.exec();
    if(!success)
    {
        qDebug() << "Update_Ressource error : " << query.lastError();
    }
    return success;
}

bool DBManager::Login_Compte(QString login, QString mdp)
{
    QSqlQuery query(db);
    query.prepare("SELECT * FROM TCompte WHERE Login = :login AND MdP = :mdp");
    query.bindValue(":login", login);
    query.bindValue(":mdp", mdp);
    return (query.exec() && query.next());
}
