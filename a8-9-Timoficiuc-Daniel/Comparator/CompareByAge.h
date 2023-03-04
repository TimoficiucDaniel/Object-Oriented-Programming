#ifndef A5_6_COMPAREBYAGE_H
#define A5_6_COMPAREBYAGE_H

#include "CompatatorBase.h"

class ComparatorAgeAsc:public Comparator<Dog>{
public:
    bool compare(Dog a, Dog b)override{
        if(a.getAge() <= b.getAge())
            return true;
        return false;
    }
};

#endif //A5_6_COMPAREBYAGE_H
