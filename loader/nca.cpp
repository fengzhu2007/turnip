#include "nca.h"
#include <QDebug>
namespace turnip {

    NCA::NCA(std::string path)
        :Loader(path),offset(-1){
        this->header = nullptr;
    }
    NCA::NCA(std::string path,std::string tik)
        :Loader(path),offset(-1){
        this->header = nullptr;


    }
    NCA::NCA(NSP* nsp,nsp_file_entry_t* file)
        :Loader(nsp->path),size(file->size),offset(nsp->headerSize + file->offset){
        //qDebug()<<"size:"<<sizeof(nsp_header_t)+nsp->NumFiles() * sizeof(nsp_file_entry_t)+nsp->header->string_table_size;
        //qDebug()<<"size:"<<sizeof(nsp_header_t)<<";s1:"<<nsp->NumFiles() * sizeof(nsp_file_entry_t)<<";s2:"<<nsp->header->string_table_size;
        this->header = nullptr;
    }

    NCA::~NCA(){
        //Loader::~Loader();
        //delete this->header;
        if(this->header!=nullptr){
            delete this->header;
            this->header = nullptr;
        }
    }

    bool NCA::Parse(){
        if(!this->ifs.is_open()){
            this->errorMsg = "NCA File open failed";
            return false;
        }
        this->ifs.seekg(this->offset);
        this->header = new nca_header_t();
        if(!this->ifs.read(reinterpret_cast<char*>(this->header),sizeof(nca_header_t))){
            this->errorMsg = "NCA File header read failed";
            return false;
        }
        if(this->header->magic==MAGIC_NCA3 || this->header->magic==MAGIC_NCA2){
            //
            return true;
        }






        return true;
    }

    size_t NCA::NumFiles(){
        //return this->header->num_files;
        return 0;
    }
}
