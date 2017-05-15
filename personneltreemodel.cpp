#include "personneltreemodel.h"

#include <QStringList>
#include <iostream>

PersonnelTreeModel::PersonnelTreeModel(QList<Ressource *> ressources, QObject *parent)
    : QAbstractItemModel(parent)
{
    rootItem = new RessourceTreeItem("");
    this->ressources= ressources;
    setupModelData();
}

PersonnelTreeModel::PersonnelTreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    rootItem = new RessourceTreeItem("");
    setupModelData();
}

PersonnelTreeModel::~PersonnelTreeModel()
{
    delete rootItem;
}

QVariant PersonnelTreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    RessourceTreeItem *item = static_cast<RessourceTreeItem *>(index.internalPointer());
    return item->data();
}

Qt::ItemFlags PersonnelTreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return QAbstractItemModel::flags(index);
}

QVariant PersonnelTreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data();

    return QVariant();
}

QModelIndex PersonnelTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
            return QModelIndex();

    RessourceTreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<RessourceTreeItem*>(parent.internalPointer());

    RessourceTreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex PersonnelTreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    RessourceTreeItem *childItem = static_cast<RessourceTreeItem*>(index.internalPointer());
    RessourceTreeItem *parentItem = childItem->parentItem();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int PersonnelTreeModel::rowCount(const QModelIndex &parent) const
{
    RessourceTreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<RessourceTreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int PersonnelTreeModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

void PersonnelTreeModel::setupModelData()
{
    RessourceTreeItem *typesItem = new RessourceTreeItem("Types");
    RessourceTreeItem *nomsItem = new RessourceTreeItem("Noms");

    RessourceTreeItem *medecinAItem = new RessourceTreeItem("Medecin A");
    typesItem->appendChild(medecinAItem);

    RessourceTreeItem *medecinBItem = new RessourceTreeItem("Medecin B");
    typesItem->appendChild(medecinBItem);

    RessourceTreeItem *radioItem = new RessourceTreeItem("Radiologue");
    typesItem->appendChild(radioItem);

    RessourceTreeItem *infirmiereItem = new RessourceTreeItem("Infirmière");
    typesItem->appendChild(infirmiereItem);

    RessourceTreeItem *kineItem = new RessourceTreeItem("Kinésithérapeute");
    typesItem->appendChild(kineItem);

    RessourceTreeItem *psychItem = new RessourceTreeItem("Psychologue");
    typesItem->appendChild(psychItem);

    RessourceTreeItem *infoItem = new RessourceTreeItem("Informaticien");
    typesItem->appendChild(infoItem);

    foreach (Ressource* ressource, this->ressources) {
        nomsItem->appendChild(new RessourceTreeItem(ressource));
        switch(ressource->getType())
        {
        case 1:
            medecinAItem->appendChild(new RessourceTreeItem(ressource));
            break;
        case 2:
            medecinBItem->appendChild(new RessourceTreeItem(ressource));
            break;
        case 3:
            radioItem->appendChild(new RessourceTreeItem(ressource));
            break;
        case 4:
            infirmiereItem->appendChild(new RessourceTreeItem(ressource));
            break;
        case 5:
            kineItem->appendChild(new RessourceTreeItem(ressource));
            break;
        case 6:
            psychItem->appendChild(new RessourceTreeItem(ressource));
            break;
        case 7:
            infoItem->appendChild(new RessourceTreeItem(ressource));
            break;
        }
    }

    rootItem->appendChild(typesItem);
    rootItem->appendChild(nomsItem);
}

void PersonnelTreeModel::update()
{
    QModelIndex topLeft = index(0, 0);
    QModelIndex bottomRight = index(rowCount() - 1, columnCount() - 1);
    emit dataChanged(topLeft, bottomRight);
    emit layoutChanged();
}

QList<Ressource *> PersonnelTreeModel::getRessources() const
{
    return ressources;
}

void PersonnelTreeModel::setRessources(const QList<Ressource *> &value)
{
    ressources = value;
    delete rootItem;
    rootItem = new RessourceTreeItem("");

    setupModelData();
    update();
}

Ressource *PersonnelTreeModel::getRessource(const QModelIndex &index)
{
    if (!index.isValid())
        return NULL;

    RessourceTreeItem *item = static_cast<RessourceTreeItem *>(index.internalPointer());
    return item->getRessource();
}
