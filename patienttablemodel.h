#ifndef PATIENTTABLEMODEL_H
#define PATIENTTABLEMODEL_H

#include <QAbstractTableModel>
#include "patient.h"
#include "dbmanager.h"

class PatientTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit PatientTableModel(const QList<Patient*>& patients, QObject *parent = 0);
    explicit PatientTableModel(QObject *parent = 0);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QVariant data(int row, int col) const;

    void update();

private:
    DBManager dbManager;
    QList<Patient*> patients;
};

#endif // PATIENTTABLEMODEL_H
