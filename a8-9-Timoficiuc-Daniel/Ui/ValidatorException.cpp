#include "ValidatorException.h"

/**
 * basic constructor
 */
ValidatorException::ValidatorException(): std::exception{}, message("") {

}
/**
 * basic copy constructor
 * @param msg
 */
ValidatorException::ValidatorException(const std::string &msg) : message(msg){

}
/**
 * returns error in printable format
 * @return
 */
const char *ValidatorException::what() {
    return this->message.c_str();
}
