
#include "Repo.h"

void Repo::readFiles() {
    std::ifstream file1("C:/Users/timod/CLionProjects/testPractic/Answers.txt");
    if(!file1.is_open())
        return;
    Answer ans;
    while(file1>>ans)
        aVector.push_back(ans);
    file1.close();

    std::ifstream file2("C:/Users/timod/CLionProjects/testPractic/Questions.txt");
    if(!file2.is_open())
        return;
    Question q;
    while(file2>>q)
        qVector.push_back(q);
    file2.close();

    std::ifstream file3("C:/Users/timod/CLionProjects/testPractic/User.txt");
    if(!file3.is_open())
           return;
    User u;
    while(file3>>u)
        uVector.push_back(u);
    file3.close();
}

void Repo::writeFiles() {
    std::ofstream file1("C/Users/timod/CLionProjects/testPractic/Answers.txt");
    if(!file1.is_open())
        return;
    for(auto a :aVector)
        file1<<a;
    file1.close();

    std::ofstream file2("C/Users/timod/CLionProjects/testPractic/Questions.txt");
    if(!file2.is_open())
        return;
    for(auto q:qVector)
        file2<<q;
    file2.close();
}

std::vector<Question>* Repo::getQuestions() {
    return &qVector;
}

std::vector<Answer>* Repo::getAnswers() {
    return &aVector;
}

std::vector<User>* Repo::getUsers() {
    return &uVector;
}

Repo::Repo(std::vector<Question> oqVector, std::vector<Answer> oaVector, std::vector<User> ouVector) {
    qVector=oqVector;
    aVector=oaVector;
    uVector=ouVector;
}
