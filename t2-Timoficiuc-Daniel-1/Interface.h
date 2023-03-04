//
// Created by timod on 5/3/2022.
//
#include "Service.h"
#include <iostream>
#ifndef TEST2_INTERFACE_H
#define TEST2_INTERFACE_H


class Interface{
private:
    Service serv;
public:
    Interface();
    void run();
    static void printMenu();
    void add();
    void showAll();
    void showEfficient();
    void save();
    void init();

};
#endif //TEST2_INTERFACE_H
