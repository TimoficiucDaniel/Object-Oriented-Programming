
#include "SourceFile.h"

std::istream &operator>>(std::istream &is, SourceFile &s) {
    if(is.eof())
    {
        is.setstate(std::ios_base::failbit);
        return is;
    }
    std::getline(is,s.name,',');
    if(s.name.empty())
        return is;
    std::getline(is,s.status,',');
    std::getline(is,s.creatorName,',');
    std::getline(is,s.reviewerName,'\n');
    return is;
}

SourceFile::SourceFile(std::string name,std::string status,std::string creator,std::string reviewer) {
    this->name = name;
    this->status = status;
    this->creatorName = creator;
    this->reviewerName = reviewer;
}

void SourceFile::setStatus(std::string status) {
    this->status = status;
}

void SourceFile::setReviewer(std::string name) {
    this->reviewerName = name;
}
