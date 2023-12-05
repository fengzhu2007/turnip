#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>
#include <stdexcept>

namespace turnip{
class Exception : public std::exception
{
public:
    Exception(std::string& msg);
    Exception(int error,std::string& msg);
    Exception(const char* msg);

    const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    std::string msg;
};
}

#endif // EXCEPTION_H
