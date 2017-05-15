#ifndef RESSOURCETREEITEM_H
#define RESSOURCETREEITEM_H
#include "ressource.h"
#include <QVariant>

class RessourceTreeItem
{
public:
    explicit RessourceTreeItem(const QString& title, RessourceTreeItem *parentItem = 0);
    explicit RessourceTreeItem(Ressource* ressource, RessourceTreeItem *parentItem = 0);
    ~RessourceTreeItem();

    void appendChild(RessourceTreeItem *child);
    void setParent(RessourceTreeItem* parent);

    RessourceTreeItem *child(int row);
    int childCount() const;
    QVariant data() const;
    int row() const;
    RessourceTreeItem *parentItem();

    Ressource *getRessource() const;
    void setRessource(Ressource *value);

private:
    QList<RessourceTreeItem *> childItems;
    RessourceTreeItem *parent;
    Ressource* ressource;
    QString title;
};

#endif // RESSOURCETREEITEM_H
