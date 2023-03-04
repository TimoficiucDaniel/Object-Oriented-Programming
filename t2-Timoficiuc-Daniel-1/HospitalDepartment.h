//
// Created by timod on 5/3/2022.
//

#include <string>

#ifndef T2_TIMOFICIUC_DANIEL_1_HOSPITALDEPARTMENT_H
#define T2_TIMOFICIUC_DANIEL_1_HOSPITALDEPARTMENT_H



class HospitalDepartment{
protected:
    std::string hospitalName;
    int numberOfDoctors;
public:
    virtual bool isEfficient()=0;
    virtual std::string toString()=0;
};

#endif //T2_TIMOFICIUC_DANIEL_1_HOSPITALDEPARTMENT_H
