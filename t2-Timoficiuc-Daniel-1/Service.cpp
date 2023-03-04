//
// Created by timod on 5/3/2022.
//

#include "Service.h"

void Service::addDepartment(HospitalDepartment *d) {
    departs.push_back(d);
}

std::vector<HospitalDepartment *> Service::getAllDepartments() {
    return departs;
}

std::vector<HospitalDepartment *> Service::getAllEfficientDepartments() {
    std::vector<HospitalDepartment *> v;
    for(auto d: departs)
    {
        if(d->isEfficient())
            v.push_back(d);
    }
    return v;

}

void Service::writeToFile(std::string filename) {
    std::ofstream f(filename);
    if(f.is_open())
    {
        for(auto d: departs)
            f<<d->toString();

        f.close();
    }
}

Service::Service() {
    departs.clear();
}
