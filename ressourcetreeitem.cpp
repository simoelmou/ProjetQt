#include "ressourcetreeitem.h"

#include <QStringList>

RessourceTreeItem::RessourceTreeItem(const QString &title, RessourceTreeItem *parentItem)
{
    this->parent = parentItem;
    this->title = title;
    this->ressource = NULL;
}

RessourceTreeItem::RessourceTreeItem(Ressource *ressource, RessourceTreeItem *parentItem)
{
    this->parent = parentItem;
    this->ressource = ressource;
}

RessourceTreeItem::~RessourceTreeItem()
{
    qDeleteAll(childItems);
}

void RessourceTreeItem::appendChild(RessourceTreeItem *child)
{
    childItems.append(child);
    child->setParent(this);
}

void RessourceTreeItem::setParent(RessourceTreeItem *parent)
{
    this->parent = parent;
}

RessourceTreeItem *RessourceTreeItem::child(int row)
{
    return childItems.value(row);
}

int RessourceTreeItem::childCount() const
{
    return childItems.count();
}

QVariant RessourceTreeItem::data() const
{
    if(ressource == NULL)
    {
        return title;
    }
    return ressource->getNom();
}

int RessourceTreeItem::row() const
{
    if (parent)
        return parent->childItems.indexOf(const_cast<RessourceTreeItem*>(this));
    return 0;
}

RessourceTreeItem *RessourceTreeItem::parentItem()
{
    return parent;
}

Ressource *RessourceTreeItem::getRessource() const
{
    return ressource;
}

void RessourceTreeItem::setRessource(Ressource *value)
{
    ressource = value;
}
