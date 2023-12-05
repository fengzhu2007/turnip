#ifndef FILESYSTEMMODAL_H
#define FILESYSTEMMODAL_H
#include <QAbstractItemModel>
namespace turnip {
namespace ui {
class FileSystemModal : public QAbstractItemModel
{

public:
    FileSystemModal(QObject *parent = 0);
    ~FileSystemModal();

    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

};
}}
#endif // FILESYSTEMMODAL_H
