#include "Interface.h"
#include <iostream>
#include <cctype>
#include <string>

/**
 * default constructor
 */
Interface::Interface() = default;
/**
 * copy constructor
 * @param admin
 * @param user
 */
Interface::Interface(Administrator admin, User user) {
    this->admin = admin;
    this->user = user;
}
/**
 * prints menu
 */
void Interface::show_menu() {
    std::cout<<"********************************\n";
    std::cout<<"0 - Exit.\n";
    std::cout<<"1 - Administrator mode.\n";
    std::cout<<"2 - User mode.\n";
    std::cout<<"********************************\n";
}
/**
 * initiates program and gives multiple choices corresponding to user/administrator modes
 */
void Interface::run() {
    this->chooseRepo();
    start:
    bool x = true;
    while (x) {
        try{
        std::cout << "********************************\n";
        this->show_menu();
        std::cout << "Which option would you like to choose?\n";
        std::string option;
        std::cin>>option;
        v.validateInteger(option);
        int intOption = stoi(option);
        v.validateOptionInterface(intOption);
        if (intOption == 1)
             this->admin.run();
        else
            if(intOption == 2)
                this->user.run();
            else
                if(intOption == 0)
                    x = false;
        } catch (ValidatorException& va){
            std::cout<<va.what();
        }
    }
}

/**
 * function that lets the user choose which type of file storage the program will use and initializes the classes
 * accordingly (html or csv)
 */
void Interface::chooseRepo() {
    start:
    std::cout<<"Choose a Repo type : 1 for CSV , 2 for HTML.\n";
    std::string option;
    std::cin>>option;
    try{
        v.validateInteger(option);
    } catch (ValidatorException& ve){
        std::cout<<ve.what();
    }
    int intOption = std::stoi(option);
    if(intOption == 1)
    {
        Database<Dog>* dogb= new CSV;
        dogb->readFromFile();
        dogb->filename ="C:/Users/timod/CLionProjects/A8-9/Repo/csv.csv";
        Service serv(dogb);
        Database<Dog>* dat= new CSV;
        dat->filename = "C:/Users/timod/CLionProjects/A8-9/Repo/csvUser.csv";
        Service userServ(dat);
        Administrator admin2(serv);
        User user2(serv,userServ);
        this->admin = admin2;
        this->user = user2;
    }
    else
        if(intOption == 2)
        {
            Database<Dog>* dogb= new HTML;
            dogb->readFromFile();
            dogb->filename = "C:/Users/timod/CLionProjects/A8-9/Repo/html.html";
            Service serv(dogb);
            Database<Dog>* dat= new HTML;
            dat->filename = "C:/Users/timod/CLionProjects/A8-9/Repo/htmlUser.html";
            Service userServ(dat);
            Administrator admin2(serv);
            User user2(serv,userServ);
            this->admin = admin2;
            this->user = user2;        }
        else{
            std::cout<<"Invalid input ... try again.\n";
            goto start;
        }
}
