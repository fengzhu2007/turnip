#include "nsp.h"
#include "../exception.h"
#include <string_view>
#include <QDebug>
namespace turnip {

NSP::NSP(std::string path)
    :Loader(path)
{
    this->header = nullptr;
}

NSP::~NSP(){
    //Loader::~Loader();
    if(this->header!=nullptr){
        delete this->header;
        this->header = nullptr;
    }
}

bool NSP::Parse(){
    if(!this->ifs.is_open()){
        //throw Exception("File open failed");
        this->errorMsg = "File open failed";
        return false;
    }

    this->header = new nsp_header_t();
    if(!this->ifs.read(reinterpret_cast<char*>(this->header),sizeof(nsp_header_t))){
        //throw Exception("File header read failed");
        this->errorMsg = "File header read failed";
        return false;
    }
    if(this->header->magic!=MAGIC_PFS0){
        //throw Exception("Invalid Magic");
        this->errorMsg = "Invalid Magic";
        return false;
    }
    this->stringTableOffset = sizeof(*this->header) + this->header->num_files * sizeof(nsp_file_entry_t);
    this->headerSize = this->stringTableOffset + this->header->string_table_size;


    for(size_t i=0;i<this->header->num_files;i++){
        nsp_file_entry_t entry;
        if(this->ifs.read(reinterpret_cast<char*>(&entry),sizeof(nsp_file_entry_t))){
            this->entries.push_back(entry);
        }
    }
    return true;
}

size_t NSP::NumFiles(){
    return this->header->num_files;
}

nsp_file_entry_t* NSP::FileEntry(size_t index){
    if(index>=this->header->num_files){
        return nullptr;
    }else{
        return &(this->entries[index]);
    }
}

std::string NSP::FileName(size_t index){
    this->ifs.seekg(this->stringTableOffset + this->entries[index].string_table_offset);
    char* buffer = new char[this->header->string_table_size];
    this->ifs.read(buffer,this->header->string_table_size);
    std::string name(buffer);
    delete[] buffer;
    return name;
}




}

