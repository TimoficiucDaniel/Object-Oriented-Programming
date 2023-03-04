//
// Created by timod on 4/5/2022.
//

#include "service.h"

Service::Service() =default;

Service::Service(Repo repo) {
    this->repo = repo;
}

/**
 * function that checks if there is another task in the repo with the same desc(returns false if there is another)
 * otherwise creates a task entity and passes it to repo to add it
 * @param desc a string
 * @param duration an int
 * @param priority an int
 * @return
 */
bool Service::addTask(std::string desc, int duration, int priority) {
        for(auto i  = this->repo.array.begin();i!=this->repo.array.end();++i)
            if(desc == i->getDesc())
                return false;
        Task t(desc,duration,priority);
        this->repo.addTask(t);
        return true;
}

int Service::getSize() {
    return this->repo.getSize();
}

Task Service::getTask(int i) {
    return this->repo.getTask(i);
}

/**
 * a function which generates a copy of the repo and then parses it multiple times
 * if there was an object that matched the given criteria then its max duration and position in array are saved to be
 * used for further comparing(so we get the element with max duration in order to sort them in descending order
 * after the parsing is over the string of the object is added to another string which will contain the output and will
 * be returned
 * then the object is removed from the copy vector
 * if the function does not find any matching object then the parsing stops and the string is returned
 * if the function finds the object then it parses another time to find other possible objects
 * if the copy vector is empty then it exits
 * @param pr an int used to filter the repo and output based on user input
 * @return
 */
std::string Service::returnPrint(int pr) {
    std::string str = "";
    std::vector<Task> copy = repo.array;
    bool ok = true;
    int maxDur = 0;
    int pos = -1;
    while (copy.size() >= 1 && ok) {
        maxDur = 0;
        pos = -1;
        ok = false;
        for (int i = 0; i < copy.size(); i++) {
            if(copy[i].getPriority()<pr)
                if(copy[i].getDuration()>maxDur)
                {
                    maxDur = copy[i].getDuration();
                    pos = i;
                    ok = true;
                }
        }
        if(ok)
            str = str + copy[pos].toString();
        for(auto i = copy.begin();i!=copy.end();++i)
            if(i->getDuration() == maxDur) {
                copy.erase(copy.begin() + pos);
                break;
            }
    }
    return str;
}
