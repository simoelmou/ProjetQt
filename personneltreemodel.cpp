#include "personneltreemodel.h"

PersonnelTreeModel::PersonnelTreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    rootItem = new QStandardItem("Personnel de soins");
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

    QStandardItem *item = static_cast<QStandardItem*>(index.internalPointer());
    return item->data(index.column());
}

Qt::ItemFlags PersonnelTreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
            return 0;

    return QAbstractItemModel::flags(index);
}

QVariant PersonnelTreeModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

QModelIndex PersonnelTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
            return QModelIndex();

    QStandardItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<QStandardItem*>(parent.internalPointer());

    QStandardItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex PersonnelTreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
            return QModelIndex();

    QStandardItem *childItem = static_cast<QStandardItem*>(index.internalPointer());
    QStandardItem *parentItem = childItem->parent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int PersonnelTreeModel::rowCount(const QModelIndex &parent) const
{
    QStandardItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<QStandardItem*>(parent.internalPointer());

    return parentItem->rowCount();
}

int PersonnelTreeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
            return static_cast<QStandardItem*>(parent.internalPointer())->columnCount();
        else
            return rootItem->columnCount();
}

void PersonnelTreeModel::setupModelData()
{
    QStandardItem *typesItem = new QStandardItem("Types");
    QStandardItem *nomsItem = new QStandardItem("Noms");

    typesItem->appendRow(new QStandardItem("Medecin A"));
    typesItem->appendRow(new QStandardItem("Medecin B"));
    typesItem->appendRow(new QStandardItem("Radiologue"));
    typesItem->appendRow(new QStandardItem("Infirmière"));
    typesItem->appendRow(new QStandardItem("Kinésithérapeute"));
    typesItem->appendRow(new QStandardItem("Psychologue"));
    typesItem->appendRow(new QStandardItem("Informaticien"));

    rootItem->appendRow(typesItem);
    rootItem->appendRow(nomsItem);
}
