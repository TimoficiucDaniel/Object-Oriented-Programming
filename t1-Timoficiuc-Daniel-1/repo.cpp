//
// Created by timod on 4/5/2022.
//

#include "repo.h"

Repo::Repo() =default;

int Repo::getSize() {
    return this->array.size();
}

/**
 * adds the task to the predefined vector using the push_back function which inserts it in the last slot of the array
 * @param t a task entity
 */
void Repo::addTask(Task t) {
    this->array.push_back(t);
}

Task Repo::getTask(int i) {
    return this->array[i];
}
