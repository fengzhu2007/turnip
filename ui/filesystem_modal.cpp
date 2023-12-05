#include "filesystem_modal.h"
namespace turnip {
namespace ui {


FileSystemModal::FileSystemModal(QObject *parent)
    :QAbstractItemModel(parent)
{

}

FileSystemModal::~FileSystemModal(){


}

QVariant FileSystemModal::data(const QModelIndex &index, int role) const{

    return QVariant();
}

Qt::ItemFlags FileSystemModal::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return 0;

    return QAbstractItemModel::flags(index);
}

QVariant FileSystemModal::headerData(int section, Qt::Orientation orientation,int role ) const {
    return QVariant();
}

QModelIndex FileSystemModal::index(int row, int column,const QModelIndex &parent) const{
    return QModelIndex();
}

QModelIndex FileSystemModal::parent(const QModelIndex &index) const{
    return QModelIndex();
}

int FileSystemModal::rowCount(const QModelIndex &parent) const {

    return 0;
}

int FileSystemModal::columnCount(const QModelIndex &parent ) const {
    return 0;
}


}}
