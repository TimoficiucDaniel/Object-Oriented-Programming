#ifndef EXAMFINAL_SERVICE_H
#define EXAMFINAL_SERVICE_H
#include "Repo.h"

class Service{
public:
    Repo r;

    Service();
    void readFiles();
    void sortFilesByName();
    bool notRevised(int i);
    bool checkIfValidFile(std::string name);
    void addFile(std::string name,std::string creator);

    std::vector<Member>* getMembers(){
        return r.getMembers();
    }
    std::vector<SourceFile>* getFiles(){
        return r.getFiles();
    }
};

#endif //EXAMFINAL_SERVICE_H
