#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vfs/filesystem.h"
#include "loader/nsp.h"
#include "loader/nca.h"
#include "exception.h"

#include <QDebug>

namespace turnip{
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //F:\BaiduYunDownload\GardenGuardian.nsp

    //std::string magic = vfs::FileSystem::magic("F:\\BaiduYunDownload\\GardenGuardian.nsp",5);
    NSP* loader = new NSP("F:\\BaiduYunDownload\\GardenGuardian.nsp");
    bool ret = loader->Parse();
    if(ret){
        size_t num = loader->NumFiles();
        for(size_t i=0;i<num;i++){
            nsp_file_entry_t* entry = loader->FileEntry(i);
            qDebug()<<"file:"<<loader->FileName(i).c_str()<<";size:"<<entry->size<<";offset:"<<entry->offset;
            NCA* nca = new NCA(loader,entry);
            ret = nca->Parse();
            if(ret){

            }else{
                qDebug()<<"exception:"<<nca->ErrorMsg().c_str();
            }
            delete nca;

            break;
        }

    }else{
        qDebug()<<"exception:"<<loader->ErrorMsg().c_str();
    }
    delete loader;
}

MainWindow::~MainWindow()
{
    delete ui;
}


}
