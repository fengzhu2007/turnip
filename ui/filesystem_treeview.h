#ifndef FILESYSTEM_TREEVIEW_H
#define FILESYSTEM_TREEVIEW_H
#include <QTreeView>
namespace turnip {
namespace ui {
    class FileSystemTreeView : public QTreeView{
        Q_OBJECT

    public:
        FileSystemTreeView(QWidget* parent);

    };
}



}
#endif // FILESYSTEM_TREEVIEW_H
