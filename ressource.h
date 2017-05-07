#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <QString>

class Ressource
{
public:
    Ressource();
    Ressource(int id, QString nom, QString prenom, int type);

    int getId() const;
    void setId(int value);

    QString getNom() const;
    void setNom(const QString &value);

    QString getPrenom() const;
    void setPrenom(const QString &value);

    int getType() const;
    void setType(int value);

private:
    int id;
    QString nom;
    QString prenom;
    int type;
};

#endif // RESSOURCE_H
