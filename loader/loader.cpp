#include "loader.h"
#include <QDebug>
namespace turnip {
    Loader::Loader(std::string path)
        :ifs(path,std::ios::binary),path(path){


    }

    Loader::~Loader(){
        if(this->ifs.is_open()){
            this->ifs.close();
        }
    }


    bool Loader::Close(){

        this->ifs.close();
        return true;
    }


}
