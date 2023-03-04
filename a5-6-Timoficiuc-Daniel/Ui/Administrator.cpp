#include "Administrator.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

/**
 * validates wether a string is an option(number)
 * @param age
 * @return
 */
bool Administrator::validateInteger(const std::string& age){
    for (char const &c: age)
        if (std::isdigit(c) == 0)
            return false;
    return true;
}
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
    if(!validateInteger(age))
    {
        std::cout<<"Invalid input for age.\n";
        goto start;
    }
    int intAge = std::stoi(age);
    if(!this->serv.addDog(name, breed, intAge, link))
        std::cout<<"Error in adding dog.\n";

}
/**
 * reads input for removing a Dog validates and then passes it to service
 */
void Administrator::removeDog() {
    start:
    std::string id;
    std::cout<<"Input id of dog to be removed.\n";
    std::cin>>id;
    if(!validateInteger(id))
    {
        std::cout<<"Invalid id!.\n";
        goto start;
    }
    int intId = stoi(id);
    if(!this->serv.removeDog(intId))
        std::cout<<"Error in removing dog.\n";

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
    if(!validateInteger(option))
    {
        std::cout<<"Invalid option format!\n";
        goto start;
    }
    int intOption = stoi(option);
    if(intOption < 1 || intOption > 4)
    {
        std::cout<<"Invalid option!\n";
        goto start;
    }
    std::string item_to_change;
    std::cout<<"Input new field.\n";
    std::cin>>item_to_change;
    std::string id;
    std::cout<<"Input id of dog to be updated.\n";
    std::cin>>id;
    if(!validateInteger(id))
    {
        std::cout<<"Invalid id!.\n";
        goto start;
    }
    int intId = stoi(id);
    if(!this->serv.updateDog(intOption,intId,item_to_change))
        std::cout<<"Error in updating dog.\n";


}
/**
 * lists all dogs in repo
 */
void Administrator::listAll() {
    if (this->serv.database.getSize() == 0)
        std::cout << "Empty database.\n";
    for(int i = 0; i < this->serv.database.getSize(); i++)
    {
        std::cout << this->serv.database.getItem(i).toString();
    }

}
/**
 *main fuction that makes up administrator mode
 * it reads input and decides what functionality to call further based on input
 */
void Administrator::run() {
    bool x = true;
    while(x){
        this->show_menu();
        std::string option;
        std::cout<<"Input option.\n";
        std::cin>>option;
        if(!validateInteger(option))
        {
            std::cout<<"Invalid option format!\n";
            goto end;
        }
        int intOption = stoi(option);
        if(intOption < 0 || intOption > 4)
        {
            std::cout<<"Invalid option!\n";
            goto end;
        }
        if(intOption == 0)
            x = false;
        else
            if(intOption == 1)
                this->addDog();
            else
                if(intOption == 2)
                    this->removeDog();
                else
                    if(intOption == 3)
                        this->updateDog();
                    else
                        if(intOption == 4)
                            this->listAll();
        end:;
    }

}

