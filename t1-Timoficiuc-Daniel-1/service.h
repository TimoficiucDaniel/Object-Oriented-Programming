//
// Created by timod on 4/5/2022.
//

#ifndef T1_TIMOFICIUC_DANIEL_1_SERVICE_H
#define T1_TIMOFICIUC_DANIEL_1_SERVICE_H
#include "repo.h"

class Service{
public:
        Repo repo;
        Service();
        Service(Repo repo);
        bool addTask(std::string desc,int duration,int priority);
        int getSize();
        Task getTask(int i);
        std::string returnPrint(int pr);
};

#endif //T1_TIMOFICIUC_DANIEL_1_SERVICE_H
