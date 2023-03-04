
#include "Member.h"

std::istream &operator>>(std::istream &is, Member &m) {
    if(is.eof())
    {
        is.setstate(std::ios_base::failbit);
        return is;
    }
    std::string revised,totalRevised;
    std::getline(is,m.name,',');
    if(m.name.empty())
        return is;
    std::getline(is,revised,',');
    std::getline(is,totalRevised,'\n');
    m.revised = stoi(revised);
    m.totalRevised = stoi(totalRevised);
    return is;
}

void Member::setEmpty() {
    this->totalRevised = 0;
}
