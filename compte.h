#ifndef COMPTE_H
#define COMPTE_H

#include <QString>

class Compte
{
public:
    Compte();
    Compte(int id, int ressource, const QString& login, const QString& mdp);

    int getId() const;
    void setId(int value);

    int getRessource() const;
    void setRessource(int value);

    QString getLogin() const;
    void setLogin(const QString &value);

    QString getMdp() const;
    void setMdp(const QString &value);

private:
    int id;
    int ressource;
    QString login;
    QString mdp;
};

#endif // COMPTE_H
