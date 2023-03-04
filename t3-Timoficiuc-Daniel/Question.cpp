
#include "Question.h"

Question::Question(int oid, std::string oText, std::string oUserName) {
    id=oid;
    text=oText;
    userName=oUserName;
}

int Question::getId() {
    return id;
}

std::string Question::getText() {
    return text;
}

std::string Question::getUserName() {
    return userName;
}

std::istream &operator>>(std::istream& is, Question& q) {
    if(is.eof())
    {
        is.setstate(std::ios_base::failbit);
        return is;
    }
    std::string idStr;
    std::getline(is,idStr,'|');
    if(idStr.empty())
        return is;
    q.id=stoi(idStr);
    std::getline(is,q.text,'|');
    std::getline(is,q.userName,'\n');
    return is;
}

std::ostream &operator<<(std::ostream &os, Question &q) {
    os<<q.id<<"|"<<q.text<<"|"<<q.userName<<"\n";
    return os;
}
