#ifndef RESSOURCELISTMODEL_H
#define RESSOURCELISTMODEL_H

#include <QAbstractListModel>

#include "ressource.h"

class RessourceListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit RessourceListModel(QList<Ressource*> ressources, QObject *parent = 0);
    explicit RessourceListModel(QObject *parent = 0);
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QList<Ressource*> getRessources() const;
    void setRessources(const QList<Ressource*> &value);

private:
    QList<Ressource*> ressources;
};

#endif // RESSOURCELISTMODEL_H
