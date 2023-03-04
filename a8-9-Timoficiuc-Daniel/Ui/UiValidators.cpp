//
// Created by timod on 5/5/2022.
//

#include "UiValidators.h"
/**
 * validates if the string input is an integer
 * @param string
 */
void UiValidator::validateInteger(const std::string &string) {
    for (char const &c: string)
        if (std::isdigit(c) == 0)
            throw ValidatorException("Incorrect format(must be an integer).\n");
}

/**
 * validates interface options,raises error if not good
 * @param option
 */
void UiValidator::validateOptionInterface(int option) {
    if(option == 1 || option == 2 || option == 0)
        return ;
    throw ValidatorException("Invalid option.\n");
}
/**
 * validates update options ,error otherwise
 * @param option
 */
void UiValidator::validateOptionUpdate(int option) {
    if(option < 1 || option > 4)
        throw ValidatorException("Incorrect option for update.\n");
}
/**
 * validates admin options, error otherwise
 * @param option
 */
void UiValidator::validateOptionAdmin(int option) {
    if(option < 0 || option > 5)
        throw ValidatorException("Incorrect option.\n");
}
/**
 * validates user options, error otherwise
 * @param option
 */
void UiValidator::validateOptionUser(int option) {
    if(option < 0 || option > 4)
        throw ValidatorException("Incorrect option.\n");
}
