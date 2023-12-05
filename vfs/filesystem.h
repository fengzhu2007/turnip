#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include <string>
#include <fstream>
namespace turnip {
namespace vfs {
    class FileSystem{

    public:
        FileSystem(std::string path);
        ~FileSystem();
        virtual bool Open();
        virtual bool Close();

        static std::string magic(std::string path,size_t size=4);


    private:
        std::ifstream* ptr;

    };
}

}
#endif // FILESYSTEM_H
