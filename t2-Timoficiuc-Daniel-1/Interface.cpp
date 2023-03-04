//
// Created by timod on 5/3/2022.
//

#include "Interface.h"

Interface::Interface() =default;

void Interface::run() {
    init();
    while(true)
    {
        int option;
        printMenu();
        std::cin>>option;
        if(option == 1)
            add();
        else
        if(option == 2)
            showAll();
        else
        if(option == 3)
            showEfficient();
        else
        if(option == 4)
            save();
        else
        if(option == 5)
            return;
        else
            std::cout<<"Invalid input\n";

    }
}

void Interface::printMenu() {
    std::cout<<"1.add department\n";
    std::cout<<"2.show all departments\n";
    std::cout<<"3.show all efficient departments\n";
    std::cout<<"4.save to file\n";
    std::cout<<"5.exit\n";
}

void Interface::add() {
    int type ;
    std::cout<<" 1 for neonatal 2 for surgery";
    std::cout<<"Input option";
    std::cin>>type;
    if( type == 1)
    {
        int mo;
        int b;
        double grade;
        int doc;
        std::cout<<"input number of doctors\n";
        std::cin>>doc;
        std::cout<<"input number of mothers\n";
        std::cin>>mo;
        std::cout<<"input number of babies\n";
        std::cin>>b;
        std::cout<<"input average grade\n";
        std::cin>>grade;
        auto n = new NeonatalUnit(doc,mo,b,grade);
        serv.addDepartment(n);
    }
    else
    if(type == 2)
    {
        int doc;
        int patients;
        std::cout<<"input number of doctors\n";
        std::cin>>doc;
        std::cout<<"input number of patients\n";
        std::cin>>patients;
        auto s = new Surgery(doc,patients);
        serv.addDepartment(s);
    }
    else
        std::cout<<"invalid type \n";
}

void Interface::showAll() {
    std::vector<HospitalDepartment*> all =serv.getAllDepartments();
    for(auto d: all)
        std::cout<<d->toString();
}

void Interface::showEfficient() {
    std::vector<HospitalDepartment*> all =serv.getAllEfficientDepartments();
    for(auto d: all)
        std::cout<<d->toString();
}

void Interface::save() {
    serv.writeToFile("C:/Users/timod/OOP Projects/t2-Timoficiuc-Daniel-1/toSave.txt");
    std::cout<<"saved to file \n";
}

void Interface::init() {
    auto a = new NeonatalUnit(10,10,20,9);
    auto b = new Surgery(10,20);
    auto c = new NeonatalUnit(10,20,19,7);
    serv.addDepartment(a);
    serv.addDepartment(b);
    serv.addDepartment(c);
}
