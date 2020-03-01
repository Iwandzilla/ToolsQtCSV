#include "tablemodel.h"

QVector<QVector<QString>> table;

TableModel::TableModel(QObject *parent) : QAbstractTableModel(parent)
{
    table.append({"Name","Age","Sex"});
    table.append({"Stanley","22","M"});
    table.append({"Kinga","22","F"});
    table.append({"Aisza","3","F"});
    table.append({"Landrynka","3","F"});
}

int TableModel::rowCount(const QModelIndex &) const
{
    return table.size();
}

int TableModel::columnCount(const QModelIndex &) const
{
    return table.at(0).size();
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case TableDataRole:
    {
        return table.at(index.row()).at(index.column());
    }
    case HeadingRole:
    {
        if(index.row() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    default:
        break;
    }

    return QVariant();
}

QHash<int, QByteArray> TableModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TableDataRole] = "tabledata";
    roles[HeadingRole] = "heading";
    return roles;
}
