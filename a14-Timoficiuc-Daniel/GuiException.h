#include "exception"
#include "string"

#ifndef QTA11_12_GUIEXCEPTION_H
#define QTA11_12_GUIEXCEPTION_H

class GuiException: public std::exception{
protected:
    std::string message;
public:
    GuiException();
    GuiException(const std::string& msg){
        message = msg;
    };
    const char* what(){
        return this->message.c_str();
    };
};


#endif //QTA11_12_GUIEXCEPTION_H
