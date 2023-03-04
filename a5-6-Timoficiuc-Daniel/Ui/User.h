#ifndef A5_6_USER_H
#define A5_6_USER_H

#include "../Service/Service.h"

class User{
    public:
        Service serv;
        Service userServ;

        User();
        explicit User(Service& serv,Service& userServ);

        void show_menu();

        void run();

        void first_option();

        void print_first_menu();

        Dog show_next_dog();

        void adopt(Dog& dog);

        void second_option();

        Dog show_next_dog_special(std::string breed , int age);

        void listAll();

        bool validateInteger(const std::string& age);


};

#endif //A5_6_USER_H
