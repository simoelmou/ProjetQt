#ifndef PERSONNELTREEMODEL_H
#define PERSONNELTREEMODEL_H

#include <QAbstractItemModel>
#include <QStandardItem>

class PersonnelTreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit PersonnelTreeModel(QObject *parent = 0);
    ~PersonnelTreeModel();

    // Basic functionality:
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                            int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                          const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

private:
    void setupModelData();

    QStandardItem *rootItem;
};

#endif // PERSONNELTREEMODEL_H
