#ifndef EXAMFINAL_REPO_H
#define EXAMFINAL_REPO_H
#include "SourceFile.h"
#include "Member.h"
#include "vector"

class Repo{
public:
    std::vector<Member> members;
    std::vector<SourceFile> files;

    std::vector<Member>* getMembers(){
        return &members;
    }
    std::vector<SourceFile>* getFiles(){
        return &files;
    }
    Repo()=default;
    void readFiles();
    void add(SourceFile s);
};

#endif //EXAMFINAL_REPO_H
