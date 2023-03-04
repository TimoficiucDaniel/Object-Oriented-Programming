#include "User.h"
#include <string>
#include <cctype>

/**
 * function that validates wether a string is a good option(number)
 * @param age
 * @return
 */
bool User::validateInteger(const std::string& age){
    for (char const &c: age)
        if (std::isdigit(c) == 0)
            return false;
    return true;
}
/**
 * default constructor
 */
User::User() = default;
/**
 * copy constructor
 * @param serv
 * @param userServ
 */
User::User(Service &serv,Service &userServ) {
    this->serv = serv;
    this->userServ = userServ;
}

/**
 * prints general menu
 */
void User::show_menu() {
    std::cout<<"********************************\n";
    std::cout<<"0 - exit .\n";
    std::cout<<"1 - show all dogs .\n";
    std::cout<<"2 - show all dogs of a certain breed and age .\n";
    std::cout<<"3 - show adoption list . \n";
    std::cout<<"********************************\n";
}

/**
 * main function of user mode that decides which functionalities to call based on user input
 *
 */
void User::run() {
    bool x = true;
    while(x)
    {
        this->serv.database.resetIterator();
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
        if(intOption < 0 || intOption > 3)
        {
            std::cout<<"Invalid option!\n";
            goto end;
        }
        if(intOption == 0)
            x = false;
        else
            if(intOption == 1)
                this->first_option();
            else
                if(intOption == 2)
                    this->second_option();
                else
                    if(intOption == 3)
                        this->listAll();
        end:;
    }

}
/**
 * function that lists all elements in repo
 */
void User::listAll() {
    if (this->userServ.database.getSize() == 0)
        std::cout << "Empty database.\n";
    for(int i = 0; i < this->userServ.database.getSize(); i++)
    {
        std::cout << this->userServ.database.getItem(i).toString();
    }

}
/**
 * function corresonding to first functionality that parses through objects in repo and lets you adopt them
 * it has multiple functionalities
 * it can read next object and display it
 * adopt the currently displayed dog
 * open its picture
 * and exit
 */
void User::first_option() {

    Dog dog=this->show_next_dog();
    bool x = true;
    bool ok = true;
    if(this->serv.database.getSize()==0)
    {
        std::cout<<"No more pets do adopt, program will now exit.\n";
        x = false;
    }
    while(x)
    {
        this->print_first_menu();
        std::string option;
        std::cout<<"Input option.\n";
        std::cin>>option;
        if(!validateInteger(option))
        {
            std::cout<<"Invalid option format!\n";
            goto end;
        }
        int intOption = stoi(option);
        if(intOption < 0 || intOption > 3)
        {
            std::cout<<"Invalid option!\n";
            goto end;
        }
        if(intOption == 0)
            x = false;
        else
            if(intOption == 1)
            {
                dog=this->show_next_dog();
                ok = true;
            }
            else
                if(intOption == 2 && ok) {
                    this->adopt(dog);
                    ok = false;
                    if(this->serv.database.getSize()==0)
                    {
                        std::cout<<"No more pets do adopt, program will now exit.\n";
                        x = false;
                    }
                }
                else
                if(intOption == 3 && ok){
                    dog.open();
                }
                else
                {
                    std::cout<<"No pet selected.\n";
                }
        end:;
    }
}

/**
 * prints menu corresponding to first and second functionalities of the run function
 */
void User::print_first_menu() {
    std::cout<<"********************************\n";
    std::cout<<"0 - exit .\n";
    std::cout<<"1 - show next dog .\n";
    std::cout<<"2 - adopt the dog .\n";
    std::cout<<"3 - open picture .\n";
    std::cout<<"********************************\n";
}
/**
 * prints the object retrieved from repo and returns it even further
 * @return
 */
Dog User::show_next_dog() {
    Dog dog=this->serv.getCurrentDog();
    std::cout<< dog.toString();
    return dog;
}
/**
 * function that lets user adopt a dog
 * aka move it from admin repo to user repo
 * @param dog
 */
void User::adopt(Dog &dog) {
    if(dog.getId()== -1)
    {
        std::cout<<"No dog to adopt.\n";
        return;
    }
    this->userServ.addDog(dog.getName(),dog.getBreed(),dog.getAge(),dog.getLink_to_photo());
    this->serv.removeDog(dog.getId());
}

/**
 * function corresponding to second functionality
 * allows user to parse through objects from a filtered list(based on breed and age)
 * allows user to adopt
 * to open pictures on web
 * and to exit
 */
void User::second_option() {
    std::cout<<"Input breed to filter by (input 0 to search all breeds).\n";
    std::string breed;
    std::cin>>breed;
    int age;
    std::cout<<"Input age to filter by.\n";
    std::cin>>age;
    Dog dog=this->show_next_dog_special(breed,age);
    bool x = true;
    bool ok = true;
    if(this->serv.database.getSize()==0) {
        std::cout << "No more pets do adopt, program will now exit.\n";
        x = false;
    }
    while(x)
    {
        this->print_first_menu();
        std::string option;
        std::cout<<"Input option.\n";
        std::cin>>option;
        if(!validateInteger(option))
        {
            std::cout<<"Invalid option format!\n";
            goto end;
        }
        int intOption = stoi(option);
        if(intOption < 0 || intOption > 3)
        {
            std::cout<<"Invalid option!\n";
            goto end;
        }
        if(intOption == 0)
            x = false;
        else
            if(intOption == 1)
            {
                dog=this->show_next_dog_special(breed,age);
                ok = true;
                if(dog.getId()==-1)
                {
                    std::cout<<"Program exits due to no dogs fitting description.\n";
                    x=false;
                    goto end;
                }
            }
            else
            if(intOption == 2 && ok) {
                ok = false;
                this->adopt(dog);
                if(this->serv.database.getSize()==0)
                {
                    std::cout<<"No more pets do adopt, program will now exit.\n";
                    x = false;
                }
            }
            else
            if(intOption ==  3 && ok)
            {
                dog.open();
            }
            else
            {
                std::cout<<"No pet to adopt.\n";
            }
        end:;
    }
}
/**
 * searches for the next object in the list that fits the filter criteria and returns it
 * if it cycles through the repo once fully without having found anything
 * it returns an empty Dog object
 * @param breed
 * @param age
 * @return
 */
Dog User::show_next_dog_special(std::string breed, int age) {
    bool ok = true;
    int timer = 0;
    Dog dog;
    while(ok)
    {
        dog = this->serv.getCurrentDog();
        if(breed.compare(dog.getBreed())==0 || breed.compare("0")== 0)
            if(dog.getAge() < age)
                ok = false;
        timer ++;
        if(timer>this->serv.database.getSize())
        {
            std::cout<<"No more dogs fit description.\n";
            goto end;
        }
    }
    std::cout<< dog.toString();
    end:;
    return dog;
}
