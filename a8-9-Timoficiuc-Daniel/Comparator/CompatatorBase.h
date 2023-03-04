#ifndef A5_6_COMPATATORBASE_H
#define A5_6_COMPATATORBASE_H

#include "../Repo/Database.h"

template <typename TElem> class Comparator{
public:
    virtual bool compare(TElem a, TElem b)=0;
};

#endif //A5_6_COMPATATORBASE_H
