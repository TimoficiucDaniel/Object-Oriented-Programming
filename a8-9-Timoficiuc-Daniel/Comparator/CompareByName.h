#ifndef A5_6_COMPAREBYNAME_H
#define A5_6_COMPAREBYNAME_H

#include "CompatatorBase.h"

class ComparatorName:public Comparator<Dog>{
public:
    bool compare(Dog a,Dog b)override{
        if(a.getName()<b.getName())
            return true;
        return false;
    }
};

#endif //A5_6_COMPAREBYNAME_H
