#ifndef A5_6_REPOEXCEPTIONS_H
#define A5_6_REPOEXCEPTIONS_H

#include <exception>
#include <string>

class RepoException: public std::exception{
protected:
    std::string message;
public:
    RepoException();
    RepoException(const std::string& msg);
    const char* what();
};

class RepoIteratorException: public RepoException{
public:
    RepoIteratorException();
    RepoIteratorException(const std::string& msg);
};

#endif //A5_6_REPOEXCEPTIONS_H
