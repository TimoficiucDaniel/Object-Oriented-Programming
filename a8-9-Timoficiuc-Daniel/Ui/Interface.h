#ifndef A5_6_INTERFACE_H
#define A5_6_INTERFACE_H


#include "../Service/Service.h"
#include "Administrator.h"
#include "User.h"

class Interface{
    private:
    Administrator admin;
    User user;
    UiValidator v;

    public:
        Interface();

        Interface(Administrator admin, User user);

        virtual void run();

        virtual void show_menu();

        void chooseRepo();
};

#endif //A5_6_INTERFACE_H
