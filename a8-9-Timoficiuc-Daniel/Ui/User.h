#ifndef A5_6_USER_H
#define A5_6_USER_H

#include "../Service/Service.h"
#include "Ui.h"

class User:public Ui{
    public:
        Service serv;
        Service userServ;

        User();
        explicit User(Service& serv,Service& userServ);

        void show_menu()override;

        void run()override;

        void first_option();

        void print_first_menu();

        Dog show_next_dog();

        void adopt(Dog& dog);

        void second_option();

        void displayList();

        Dog show_next_dog_special(std::string breed , int age);

        void listAll();


};

#endif //A5_6_USER_H
