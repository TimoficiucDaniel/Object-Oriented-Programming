#ifndef TESTPRACTIC_USER_H
#define TESTPRACTIC_USER_H
#include <string>
#include "fstream"
class User{
private:
    std::string name;
public:
    User()=default;
    User(std::string oName);

    std::string getName();

    friend std::istream &operator>>(std::istream& is, User& u);
};

#endif //TESTPRACTIC_USER_H
