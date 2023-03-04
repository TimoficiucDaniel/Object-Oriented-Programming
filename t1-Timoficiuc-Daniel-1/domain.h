//
// Created by timod on 4/5/2022.
//

#ifndef T1_TIMOFICIUC_DANIEL_1_DOMAIN_H
#define T1_TIMOFICIUC_DANIEL_1_DOMAIN_H
#include <string>
class Task{
    private:
        std::string description;
        int duration;
        int priority;
    public:

        Task();
        Task(std::string description,int duration,int priority);
        int getDuration();
        int getPriority();
        std::string toString();
        std::string getDesc();
};

#endif //T1_TIMOFICIUC_DANIEL_1_DOMAIN_H
