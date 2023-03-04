//
// Created by timod on 4/5/2022.
//
#include "ui.h"

int main(){
    Repo repo;
    Service serv(repo);
    serv.addTask("Solve_OOP_assignment",120,1);
    serv.addTask("Respond_to_emails",45,2);
    serv.addTask("Eat_sushi",30,3);
    serv.addTask("Visit_parent",240,1);
    serv.addTask("Buy_a_jacket",120,2);
    Ui ui(serv);
    ui.run();
};