#include "Repo.h"

void Repo::readFiles() {
    std::ifstream file1("C:/Users/timod/CLionProjects/ExamFinal/Members.txt");

    if(!file1.is_open())
        return;
    Member m;
    while(file1>>m)
        members.push_back(m);

    file1.close();

    std::ifstream file2("C:/Users/timod/CLionProjects/ExamFinal/SourceFiles.txt");

    if(!file2.is_open())
        return;
    SourceFile s;
    while(file2>>s)
        files.push_back(s);

    file2.close();
}

void Repo::add(SourceFile s) {
    files.push_back(s);
}
