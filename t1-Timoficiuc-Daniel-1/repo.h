//
// Created by timod on 4/5/2022.
//

#ifndef T1_TIMOFICIUC_DANIEL_1_REPO_H
#define T1_TIMOFICIUC_DANIEL_1_REPO_H
#include <vector>
#include "domain.h"

class Repo{
    public:
        std::vector<Task> array;
        Repo();
        int getSize();
        void addTask(Task t);
        Task getTask(int i);


};


#endif //T1_TIMOFICIUC_DANIEL_1_REPO_H
