#include "User.h"

User::User(std::string oName) {
 name=oName;
}

std::istream &operator>>(std::istream &is, User &u) {
    if(is.eof())
    {
        is.setstate(std::ios_base::failbit);
        return is;
    }
    std::getline(is,u.name,'\n');
    return is;
}

std::string User::getName() {
    return name;
}

