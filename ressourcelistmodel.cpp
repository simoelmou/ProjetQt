#include "ressourcelistmodel.h"

RessourceListModel::RessourceListModel(QList<Ressource *> ressources, QObject *parent)
    : QAbstractListModel(parent)
{
    this->ressources = ressources;
}

RessourceListModel::RessourceListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int RessourceListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return ressources.size();
}

QVariant RessourceListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= ressources.size())
            return QVariant();

    if (role == Qt::DisplayRole)
        return ressources.at(index.row())->getNom();
    else
        return QVariant();
}

QList<Ressource*> RessourceListModel::getRessources() const
{
    return ressources;
}

void RessourceListModel::setRessources(const QList<Ressource *> &value)
{
    ressources = value;
}
