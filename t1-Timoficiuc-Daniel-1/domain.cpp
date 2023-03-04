//
// Created by timod on 4/5/2022.
//

#include "domain.h"

Task::Task() =default;

Task::Task(std::string description, int duration, int priority) {
    this->description = description;
    this->duration =duration;
    this->priority =priority;
}

int Task::getDuration() {
    return this->duration;
}

int Task::getPriority() {
    return this->priority;
}

std::string Task::toString() {
    std::string str ="";
    std::string intDuration = std::to_string(duration);
    std::string intPriority = std::to_string(priority);
    str = str+ "Task with description "+ description +" lasts " + intDuration +" and has priority of " +intPriority +
            "\n";
    return str;
}

std::string Task::getDesc() {
    return this->description;
}
