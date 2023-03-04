//
// Created by timod on 5/3/2022.
//

#include "HospitalDepartment.h"

#ifndef T2_TIMOFICIUC_DANIEL_1_NEONATALUNIT_H
#define T2_TIMOFICIUC_DANIEL_1_NEONATALUNIT_H

class NeonatalUnit: public HospitalDepartment {
private:
    int numberOfMothers;
    int numberOfNewborns;
public:
    double averageGrade;
    NeonatalUnit(int doc, int mo, int b , double grade){
        hospitalName ="";
        numberOfDoctors = doc;
        numberOfMothers = mo;
        numberOfNewborns = b;
        averageGrade = grade;
    }
    bool isEfficient() override{
        if(averageGrade > 8.5 )
            if(numberOfNewborns >= numberOfMothers)
                return true;
        return false;
    }
    std::string toString()override{
        std::string toReturn = "Neonatal Unit " + hospitalName + " number of doc " + std::to_string(numberOfDoctors) +
                " number of patients " + std::to_string(numberOfMothers) + " number of babies " + std::to_string(numberOfNewborns)
                + " average grade " + std::to_string(averageGrade) + " Efficient status " + std::to_string(isEfficient())
                + "\n";
        return toReturn;
    }

};

#endif //T2_TIMOFICIUC_DANIEL_1_NEONATALUNIT_H
