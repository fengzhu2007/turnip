#include "exception.h"


namespace turnip{

Exception::Exception(std::string& msg)
    :msg(msg){


}

Exception::Exception(int error,std::string& msg)
    :msg(msg){


}

Exception::Exception(const char* msg):msg(msg){

}



}
