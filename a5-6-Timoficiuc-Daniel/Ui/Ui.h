#ifndef A5_6_UI_H
#define A5_6_UI_H

#include "Administrator.h"
#include "User.h"

class Ui{
    private:
    Administrator admin;
    User user;

    public:
        Ui();
        Ui(Administrator admin,User user);
        void run();
        void show_menu();
};

#endif //A5_6_UI_H
