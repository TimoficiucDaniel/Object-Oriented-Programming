

#ifndef EXAMFINAL_SOURCEFILE_H
#define EXAMFINAL_SOURCEFILE_H
#include "string"
#include "fstream"

class SourceFile{
public:
    std::string name;
    std::string status;
    std::string creatorName;
    std::string reviewerName;

    std::string getName(){
        return name;
    }
    std::string getStatus(){
        return status;
    }
    std::string getCreatorName(){
        return creatorName;
    }
    std::string getReviewerName(){
        return reviewerName;
    }
    void setStatus(std::string status);
    void setReviewer(std::string name);
    SourceFile()=default;
    SourceFile(std::string name,std::string status,std::string creator,std::string reviewer);
    friend std::istream &operator>>(std::istream& is,SourceFile& s);
};
#endif //EXAMFINAL_SOURCEFILE_H
