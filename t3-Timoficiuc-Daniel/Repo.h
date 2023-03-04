#ifndef TESTPRACTIC_REPO_H
#define TESTPRACTIC_REPO_H
#include "Question.h"
#include "Answer.h"
#include "User.h"
#include <vector>

class Repo{
private:
    std::vector<Question> qVector;
    std::vector<Answer> aVector;
    std::vector<User> uVector;
public:

    Repo()=default;
    Repo(std::vector<Question> oqVector,std::vector<Answer> oaVector, std::vector<User> ouVector);

    void readFiles();
    void writeFiles();

    std::vector<Question>* getQuestions();
    std::vector<Answer>* getAnswers();
    std::vector<User>* getUsers();
};

#endif //TESTPRACTIC_REPO_H
