//
// Created by timod on 5/3/2022.
//
#include <vector>
#include "HospitalDepartment.h"
#include "NeonatalUnit.h"
#include "Surgery.h"
#include <fstream>

#ifndef T2_TIMOFICIUC_DANIEL_1_SERVICE_H
#define T2_TIMOFICIUC_DANIEL_1_SERVICE_H

class Service{
private:
    std::vector<HospitalDepartment*> departs;
public:

    Service();
    void addDepartment(HospitalDepartment* d);
    std::vector<HospitalDepartment*> getAllDepartments();
    std::vector<HospitalDepartment*> getAllEfficientDepartments();
    void writeToFile(std::string filename);
};

#endif //T2_TIMOFICIUC_DANIEL_1_SERVICE_H
