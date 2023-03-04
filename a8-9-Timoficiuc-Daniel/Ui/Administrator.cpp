#include "Administrator.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>


/**
 * default constructor
 */
Administrator::Administrator() = default;
/**
 * copy constructor
 * @param serv
 */
Administrator::Administrator(Service &serv) {
    this->serv = serv;
}
/**
 * prints menu
 */
void Administrator::show_menu() {
    std::cout<<"********************************\n";
    std::cout<<"0 - Exit.\n";
    std::cout<<"1 - Add dog.\n";
    std::cout<<"2 - Remove dog.\n";
    std::cout<<"3 - Update dog.\n";
    std::cout<<"4 - List all dogs.\n";
    std::cout<<"5 - Display file.\n";
    std::cout<<"********************************\n";
}
/**
 * reads input for a Dog objects validates it and then passes it on to service
 */
void Administrator::addDog() {
    start:
    std::string name;
    std::string breed;
    std::string link;
    std::string age;
    std::cout<<"Input name.\n";
    std::cin>>name;
    std::cout<<"Input breed.\n";
    std::cin>>breed;
    std::cout<<"Input age.\n";
    std::cin>>age;
    std::cout<<"Input link.\n";
    std::cin>>link;
    try {
        v.validateInteger(age);
    } catch (ValidatorException& ve){
        std::cout<<ve.what();
        goto start;
    }
    int intAge = std::stoi(age);
    try {
        this->serv.addDog(name, breed, intAge, link);
    }catch (RepoException& r){
        std::cout<<r.what();
    }

}
/**
 * reads input for removing a Dog validates and then passes it to service
 */
void Administrator::removeDog() {
    start:
    std::string id;
    std::cout<<"Input id of dog to be removed.\n";
    std::cin>>id;
    try{
        v.validateInteger(id);
    } catch (ValidatorException& ve){
        std::cout<<ve.what();
        goto start;
    }
    int intId = stoi(id);
    try {
        this->serv.removeDog(intId);
    } catch( RepoException& r){
        std::cout<<r.what();
    }

}
/**
 * prints menu for update
 */
void print_update_menu(){
    std::cout<<"********************************\n";
    std::cout<<"1 - name.\n2 - breed.\n3 - age.\n4 - link.\n";
    std::cout<<"********************************\n";
}
/**
 * function that reads the input corresponding to what object to be updated , what attribute
 * and how it should be modified
 * then validates it and passes it to service
 */
void Administrator::updateDog() {
    start:
    print_update_menu();
    std::string option;
    std::cout<<"Select item to update.\n";
    std::cin>>option;
    try {
        v.validateInteger(option);
    }catch (ValidatorException& ve){
        std::cout<<ve.what();
        goto start;
    }
    int intOption = stoi(option);
    try{
        v.validateOptionUpdate(intOption);
    } catch (ValidatorException& ve){
        std::cout<<ve.what();
        goto start;
    }
    std::string item_to_change;
    std::cout<<"Input new field.\n";
    std::cin>>item_to_change;
    std::string id;
    std::cout<<"Input id of dog to be updated.\n";
    std::cin>>id;
    try {
        v.validateInteger(id);
    }catch (ValidatorException& ve){
        std::cout<<ve.what();
        goto start;
    }
    int intId = stoi(id);
    try {
        this->serv.updateDog(intOption, intId, item_to_change);
    } catch (RepoException& r) {
        std::cout << r.what();
    }

}
/**
 * lists all dogs in repo
 */
void Administrator::listAll() {
    if (this->serv.getSize() == 0)
        std::cout << "Empty database.\n";
    for(int i = 0; i < this->serv.getSize(); i++)
    {
        std::cout << this->serv.getDog(i).toString();
    }

}
/**
 *main function that makes up administrator mode
 * it reads input and decides what functionality to call further based on input
 */
void Administrator::run() {
    bool x = true;
    while (x) {
        try {
            this->show_menu();
            std::string option;
            std::cout << "Input option.\n";
            std::cin >> option;
            v.validateInteger(option);
            int intOption = stoi(option);
            v.validateOptionAdmin(intOption);
            if (intOption == 0)
                x = false;
            else if (intOption == 1)
                this->addDog();
            else if (intOption == 2)
                this->removeDog();
            else if (intOption == 3)
                this->updateDog();
            else if (intOption == 4)
                this->listAll();
            else if (intOption == 5)
                this->displayFile();
            }catch (ValidatorException& ve){
            std::cout<<ve.what();
        }

    }
    this->serv.database->storeToFileBasic();
}

/**
 * opens file in the respective format
 */
void Administrator::displayFile() {
    this->serv.openFile();
}
