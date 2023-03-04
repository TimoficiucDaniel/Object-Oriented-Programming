#include "Answer.h"

Answer::Answer(int oid, int oQuestionId,std::string oUserName,std::string oText, int oVotes) {
    id=oid;
    questionId=oQuestionId;
    userName=oUserName;
    text=oText;
    votes=oVotes;
}

int Answer::getQuestionId() {
    return questionId;
}

int Answer::getVotes() {
    return votes;
}

std::string Answer::getUserName() {
    return userName;
}

std::string Answer::getText() {
    return text;
}

std::istream &operator>>(std::istream &is, Answer &ans) {
    if(is.eof())
    {
        is.setstate(std::ios_base::failbit);
        return is;
    }
    std::string idStr,questionIdStr,votesStr;
    std::getline(is,idStr,'|');
    if(idStr.empty())
        return is;
    std::getline(is,questionIdStr,'|');
    std::getline(is,ans.userName,'|');
    std::getline(is,ans.text,'|');
    std::getline(is,votesStr,'\n');
    ans.id=stoi(idStr);
    ans.questionId=stoi(questionIdStr);
    ans.votes=stoi(votesStr);

    return is;
}

int Answer::getId() {
    return id;
}

std::ostream &operator<<(std::ostream &os, Answer &ans) {
    os<<ans.id<<"|"<<ans.questionId<<"|"<<ans.userName<<"|"<<ans.text<<"|"<<ans.votes<<"\n";
    return os;
}
