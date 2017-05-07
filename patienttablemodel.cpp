#include "patienttablemodel.h"
#include <QPushButton>

PatientTableModel::PatientTableModel(const QList<Patient*>& patients, QObject *parent)
    : QAbstractTableModel(parent)
{
    this->patients = patients;
}

PatientTableModel::PatientTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    this->patients = dbManager.GetAll_Patient();
}

QVariant PatientTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
            return QVariant();

    if (orientation == Qt::Horizontal) {
        switch(section)
        {
        case 0:
            return "Nom";
        case 1:
            return "Prenom";
        case 2:
            return "Date de rendez-vous";
        case 3:
            return "Numéro d'identification";
        case 4:
            return "Modifier";
        case 5:
            return "Supprimer";
        }
    }
    return QVariant();
}

int PatientTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return patients.count();
}

int PatientTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 6;
}

QVariant PatientTableModel::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole || !index.isValid() ||
            index.row() >= this->patients.count() || index.column() >= this->columnCount())
    {
        return QVariant();
    }
    switch(index.column())
    {
    case 0:
        return patients.at(index.row())->getNom();
    case 1:
        return patients.at(index.row())->getPrenom();
    case 2:
        return patients.at(index.row())->getDateConsultation();
    case 3:
        return patients.at(index.row())->getId();
    case 4:
        return "modifier";
    case 5:
        return "supprimer";
    }

    return QVariant();
}

QVariant PatientTableModel::data(int row, int col) const
{
    if (row >= this->patients.count() || col >= this->columnCount())
    {
        return QVariant();
    }
    switch(col)
    {
    case 0:
        return patients.at(row)->getNom();
    case 1:
        return patients.at(row)->getPrenom();
    case 2:
        return patients.at(row)->getDateConsultation();
    case 3:
        return patients.at(row)->getId();
    case 4:
        return "modifier";
    case 5:
        return "supprimer";
    }

    return QVariant();
}

void PatientTableModel::update()
{
    this->patients = dbManager.GetAll_Patient();

    QModelIndex topLeft = index(0, 0);
    QModelIndex bottomRight = index(rowCount() - 1, columnCount() - 1);
    emit dataChanged(topLeft, bottomRight);
    emit layoutChanged();
}
