#ifndef LOADER_H
#define LOADER_H
#include <string>
#include <fstream>
namespace turnip {
class Loader {
public:
    Loader(std::string path);
    virtual ~Loader();

    bool Close();

    virtual bool Parse()=0;
    virtual size_t NumFiles()=0;

    inline std::string ErrorMsg(){return this->errorMsg;}
    inline int ErrorNo(){return this->errorNo;}



protected:
    std::ifstream ifs;
    std::string path;
    std::string errorMsg;
    int errorNo;



friend class NCA;
};
}
#endif // LOADER_H
