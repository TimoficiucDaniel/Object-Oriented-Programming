
#ifndef TESTPRACTIC_QUESTION_H
#define TESTPRACTIC_QUESTION_H
#include "string"
#include "fstream"
class Question{
private:
    int id;
    std::string text;
    std::string userName;
public:
    Question()=default;
    Question(int oid,std::string oText, std::string oUserName);

    int getId();
    std::string getText();
    std::string getUserName();

    friend std::istream &operator>>(std::istream& is, Question& q);
    friend std::ostream &operator<<(std::ostream& os, Question& q);
};

#endif //TESTPRACTIC_QUESTION_H
