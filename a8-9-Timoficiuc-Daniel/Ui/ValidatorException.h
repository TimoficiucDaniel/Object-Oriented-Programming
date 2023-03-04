#ifndef A5_6_VALIDATOREXCEPTION_H
#define A5_6_VALIDATOREXCEPTION_H
#include "string"
#include "iostream"
#include "exception"

class ValidatorException: public std::exception{
protected:
    std::string message;
public:
    ValidatorException();
    ValidatorException(const std::string& msg);
    const char* what();
};
#endif //A5_6_VALIDATOREXCEPTION_H
