
#include "RepoExceptions.h"
/**
 * basic constructor with empty error message
 */
RepoException::RepoException() : std::exception{}, message{""} {
}
/**
 * copy constructor which assigns an error to the message
 * @param msg
 */
RepoException::RepoException(const std::string &msg): message{msg} {

}

/**
 * returns the exception in a printable format
 * @return
 */
const char *RepoException::what() {
    return this->message.c_str();
}

/**
 * basic constructor with empty error message
 */
RepoIteratorException::RepoIteratorException(): RepoException{} {
        message = "";
}
/**
 * copy constructor which assigns an error to the message
 * @par
 */
RepoIteratorException::RepoIteratorException(const std::string &msg) : RepoException(msg) {
        message = msg;
}

