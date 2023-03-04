#ifndef TESTPRACTIC_ANSWER_H
#define TESTPRACTIC_ANSWER_H
#include <string>
#include <fstream>
class Answer{
private:
    int id;
    int questionId;
    std::string userName;
    std::string text;
    int votes;
public:

    Answer()=default;
    Answer(int oid,int oQuestionId,std::string oUserName,std::string oText, int oVotes);

    int getId();
    int getQuestionId();
    int getVotes();
    std::string getUserName();
    std::string getText();

    friend std::istream &operator>>(std::istream& is,Answer& ans );
    friend std::ostream &operator<<(std::ostream& os,Answer& ans);
};

#endif //TESTPRACTIC_ANSWER_H
