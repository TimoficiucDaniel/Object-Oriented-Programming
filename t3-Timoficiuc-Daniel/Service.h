#ifndef TESTPRACTIC_SERVICE_H
#define TESTPRACTIC_SERVICE_H
#include "Repo.h"

class Service{
private:
    Repo r;
public:
    Service();
    Service(Repo& otherRepo);

    std::vector<Question>* getQuestions();
    std::vector<Answer>* getAnswers();
    std::vector<User>* getUsers();

    void sortQuestionsByAnswers();
    int getSize();
    int findBestMatchingQuestion(std::string data);
    void sortAnswersByVotes();
    std::vector<Answer> getAnswersForQuestion(Question q);
};

#endif //TESTPRACTIC_SERVICE_H
