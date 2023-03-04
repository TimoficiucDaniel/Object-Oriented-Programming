#include "string"
#include "GuiException.h"

#ifndef QTA11_12_GUIVALIDATOR_H
#define QTA11_12_GUIVALIDATOR_H

class GuiValidator{
public:
    void validateInteger(const std::string &string){
        for (char const &c: string)
            if (std::isdigit(c) == 0)
                throw GuiException("Incorrect format(must be an integer)");
    };

    void checkIfStringEmpty(const std::string &string){
        if(string=="")
            throw GuiException("Empty fields");
    };
};

#endif //QTA11_12_GUIVALIDATOR_H
