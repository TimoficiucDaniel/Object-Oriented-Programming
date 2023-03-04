#ifndef A5_6_UIVALIDATORS_H
#define A5_6_UIVALIDATORS_H


#include "ValidatorException.h"

class UiValidator{
public:
    UiValidator()=default;

    void validateInteger(const std::string &string);

    void validateOptionInterface(int option);

    void validateOptionUpdate(int option);

    void validateOptionAdmin(int option);

    void validateOptionUser(int option);


};

#endif //A5_6_UIVALIDATORS_H
