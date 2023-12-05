#include "filesystem.h"
#include <QDebug>
namespace turnip {
namespace vfs {


FileSystem::FileSystem(std::string path){
    this->ptr = new std::ifstream(path, std::ios::in);
}

FileSystem::~FileSystem(){
    if(this->ptr){
        delete this->ptr;
        this->ptr = nullptr;
    }
}

bool FileSystem::Open(){

    return true;
}

bool FileSystem::Close(){

    return true;

}

std::string FileSystem::magic(std::string path,size_t size){
    //NSP -> PFS
    auto ifs = std::ifstream(path,std::ios::in);
    if(ifs.fail()){
        qDebug()<<"magic error";
        return "";
    }else{
        char* magic = new char[size+1];
        //ifs.seekg(256);
        ifs.getline(magic,size+1);
        qDebug()<<"magic:"<<magic;
        std::string m(magic);
        delete[] magic;
        ifs.close();
        return m;
    }
}


}

}
