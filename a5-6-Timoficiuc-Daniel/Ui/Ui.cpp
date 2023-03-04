#include "Ui.h"
#include <iostream>
#include <cctype>
#include <string>

/**
 *function used to validate whether a string is an option(number)
 * @param option
 * @return
 */
bool validate(int option){
    if(option == 1 || option == 2 || option == 0)
        return true;
    return false;
}
/**
 * default constructor
 */
Ui::Ui() = default;
/**
 * copy constructor
 * @param admin
 * @param user
 */
Ui::Ui(Administrator admin,User user) {
    this->admin = admin;
    this->user = user;
}
/**
 * prints menu
 */
void Ui::show_menu() {
    std::cout<<"********************************\n";
    std::cout<<"0 - Exit.\n";
    std::cout<<"1 - Administrator mode.\n";
    std::cout<<"2 - User mode.\n";
    std::cout<<"********************************\n";
}
/**
 * initiates program and gives multiple choices corresponding to user/administrator modes
 */
void Ui::run() {
    start:
    bool x = true;
    while (x) {
        std::cout << "********************************\n";
        this->show_menu();
        std::cout << "Which option would you like to choose?\n";
        std::string option;
        std::cin>>option;
        for (char const &c: option)
            if (std::isdigit(c) == 0) {
                std::cout << "Invalid option format!\n";
                goto start;
            }
        int intOption = stoi(option);
        if (!validate(intOption)) {
            std::cout << "Please input a valid option.\n";
            goto start;
        }
        if (intOption == 1)
             this->admin.run();
        else
            if(intOption == 2)
                this->user.run();
            else
                if(intOption == 0)
                    x = false;
    }
}