
#include "MyModel.h"


MyModel::MyModel(Database<Dog>* other,QObject *parent)
        : QAbstractTableModel(parent)
{
    this->d = other;
}

int MyModel::rowCount(const QModelIndex & /*parent*/) const
{
    return this->d->getSize();
}

int MyModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 4;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int column = index.column();

    std::vector<Dog> dogs = this->d->getElems();

    if (row == dogs.size())
    {
        return QVariant();
    }

    Dog g = dogs[row];

    if (role == Qt::DisplayRole)
    {
        switch (column)
        {
            case 0:
                return QString::fromStdString(g.getName());
            case 1:
                return QString::fromStdString(g.getBreed());
            case 2:
                return QString::fromStdString(std::to_string(g.getAge()));
            case 3:
                return QString::fromStdString(g.getLink_to_photo());
            default:
                break;
        }
    }
    return QVariant();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
                case 0:
                    return QString{ "Dog name" };
                case 1:
                    return QString{ "Breed" };
                case 2:
                    return QString{ "Age" };
                case 3:
                    return QString{"Link"};
                default:
                    break;
            }
        }
    }
    return QVariant{};
}
