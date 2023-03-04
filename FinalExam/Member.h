#ifndef EXAMFINAL_MEMBER_H
#define EXAMFINAL_MEMBER_H
#include "string"
#include "fstream"

class Member{
public:
    std::string name;
    int revised;
    int totalRevised;

    std::string getName(){
        return name;
    }
    int getRevised(){
        return revised;
    }
    int getTotalRevised(){
        return totalRevised;
    }
    void incRevised(){
        revised++;
    }
    void decTotalRevised(){
        totalRevised--;
    }
    void setEmpty();
    Member()=default;
    friend std::istream  &operator>>(std::istream& is, Member& m );
};

#endif //EXAMFINAL_MEMBER_H
