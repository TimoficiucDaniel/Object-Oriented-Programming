#ifndef QTA11_12_MYMODEL_H
#define QTA11_12_MYMODEL_H

#include <QAbstractTableModel>
#include "Database.h"
class MyModel : public QAbstractTableModel
{
Q_OBJECT
public:
    Database<Dog>* d;
    MyModel(Database<Dog>* d,QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

};

#endif //QTA11_12_MYMODEL_H
