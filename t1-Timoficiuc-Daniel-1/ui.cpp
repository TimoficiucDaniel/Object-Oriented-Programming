//
// Created by timod on 4/5/2022.
//

#include "ui.h"

Ui::Ui() =default;

Ui::Ui(Service serv) {
    this->serv =serv;
}

void Ui::run() {
    bool x = true;
    while(x){
        this->showMenu();
        int option ;
        std::cin>>option;
        if(option == 0)
            x = false;
        else
        if(option == 1)
            this->addTask();
        else
        if(option == 2)
            this->showAll();
        else
        if(option == 3)
            this->showFiltered();
        else
            std::cout<<"invalid input\n";
    }
}

void Ui::addTask() {
    std::string desc;
    int duration;
    int priority;
    std::cout<<"Input description\n";
    std::cin>>desc;
    std::cout<<"Input duration\n";
    std::cin>>duration;
    std::cout<<"Input priority\n";
    std::cin>>priority;
    if(!this->serv.addTask(desc,duration,priority))
        std::cout<<"Error\n";
    else
        std::cout<<"Success\n";
}

void Ui::showAll() {
    for(int i = 0 ;i< this->serv.getSize();i++)
        std::cout<<this->serv.getTask(i).toString();
}

void Ui::showFiltered() {
    int priorityFilter;
    std::cout<<"Input priority to filter by\n";
    std::cin>>priorityFilter;
    std::cout<<this->serv.returnPrint(priorityFilter);
}

void Ui::showMenu() {
    std::cout<<"0 - exit\n1 - add \n2 - show all \n3 - show all with a priority less than one given via input and"
               "sorted descending based on duration\n";
}
