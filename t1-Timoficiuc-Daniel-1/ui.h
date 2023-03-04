//
// Created by timod on 4/5/2022.
//

#ifndef T1_TIMOFICIUC_DANIEL_1_UI_H
#define T1_TIMOFICIUC_DANIEL_1_UI_H
#include "service.h"
#include <iostream>

class Ui{
    private:
        Service serv;

    public:
        Ui();
        Ui(Service serv);
        void run();
        void addTask();
        void showAll();
        void showFiltered();
        void showMenu();

};


#endif //T1_TIMOFICIUC_DANIEL_1_UI_H
