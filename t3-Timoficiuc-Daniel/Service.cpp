#include "Service.h"

Service::Service() {
    r.readFiles();
}

Service::Service(Repo &otherRepo) {
    r=otherRepo;
}

std::vector<Question>* Service::getQuestions() {
    return r.getQuestions();
}

std::vector<Answer>* Service::getAnswers() {
    return r.getAnswers();
}

std::vector<User>* Service::getUsers() {
    return r.getUsers();
}

int Service::getSize() {
    return r.getUsers()->size();
}

void Service::sortQuestionsByAnswers() {
    std::vector<int> answersNumbers;
    for(auto q: *getQuestions())
    {
        int count = 0;
        for(auto a: *getAnswers())
            if(a.getQuestionId() == q.getId())
                count++;
        answersNumbers.push_back(count);
    }
    for(int i = 0 ;i<answersNumbers.size();i++)
        for(int j=i;j<answersNumbers.size();j++)
            if(answersNumbers[i]<answersNumbers[j])
            {
                std::swap(answersNumbers[i],answersNumbers[j]);
                std::swap((*getQuestions())[i],(*getQuestions())[j]);
            }
}

int Service::findBestMatchingQuestion(std::string data) {
    std::vector<int> matchingScore;
    for (auto q: *r.getQuestions()) {
        int i = 0;
        int count = 0;
        while (i < q.getText().size() and i < data.size()) {
            if (q.getText()[i] == data[i])
                count++;
            i++;
        }
        matchingScore.push_back(count);
    }
    int maxId, max = 0, i = 0;
    for (auto q: *r.getQuestions()){
        if (max < matchingScore[i]) {
            max = matchingScore[i];
            maxId = q.getId();
        }
        i++;
}
    return maxId;
}

void Service::sortAnswersByVotes() {
    for(int i = 0 ; i < getAnswers()->size(); i++)
        for(int j=i; j < getAnswers()->size(); j++)
            if((*getAnswers())[i].getVotes() < (*getAnswers())[j].getVotes())
            {
                std::swap((*getAnswers())[i],(*getAnswers())[j]);
            }
}

std::vector<Answer> Service::getAnswersForQuestion(Question q) {
    std::vector<Answer> answers;
    for(auto a : *getAnswers())
        if(a.getQuestionId() == q.getId())
            answers.push_back(a);
    return answers;
}
