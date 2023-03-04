//
// Created by timod on 5/3/2022.
//
#include "HospitalDepartment.h"

#ifndef T2_TIMOFICIUC_DANIEL_1_SURGERY_H
#define T2_TIMOFICIUC_DANIEL_1_SURGERY_H

class Surgery: public HospitalDepartment{
private:
    int numberOfPatients;
public:
    Surgery(int doc, int pa ){
        hospitalName = "";
        numberOfDoctors = doc;
        numberOfPatients = pa;
    }
    bool isEfficient() override{
     if(numberOfDoctors*2 >= numberOfPatients)
         return true;
     return false;
    }
    std::string toString() override{
        std::string toReturn = "Surgery " + hospitalName + " number of doc " + std::to_string(numberOfDoctors) +
                               " number of patients " + std::to_string(numberOfPatients) + " Efficient status " +
                               std::to_string(isEfficient()) + "\n";
        return toReturn;
    }
};

#endif //T2_TIMOFICIUC_DANIEL_1_SURGERY_H
