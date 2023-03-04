#include "Ui/Interface.h"
#include "Comparator/CompareByAge.h"
#include "Comparator/CompareByName.h"
#include "Test.h"
#include "cassert"

#include "iostream"

class Main{
public:
    void run(){
        Interface i ;
        i.run();
    }
};
template <typename TElem> class Sort {
public:
    void SortElem(std::vector<TElem> &v, Comparator<TElem> *c) {
        for (int i = 0; i <= v.size(); i++)
            for (int j = i + 1; j < +v.size(); j++)
                if (!c->compare(v[i], v[j]))
                    std::swap(v[i], v[j]);
    }
};

void TestSort() {
    std::vector<Dog> a;
    Dog d1("a", "j", "c", 14);
    Dog d2("d", "c", "f", 13);
    Dog d3("g", "b", "i", 12);
    Dog d4("j", "a", "l", 11);
    a.push_back(d1);
    a.push_back(d2);
    a.push_back(d3);
    a.push_back(d4);
    std::vector<Dog> b;
    std::vector<Dog> c;
    b = a;
    c = a;
    Comparator<Dog> *c1 = new ComparatorAgeAsc;
    Comparator<Dog> *c2 = new ComparatorName;
    Sort<Dog> s;
    s.SortElem(b, c1);
    s.SortElem(c, c2);
    for (int i = 1; i < b.size(); i++) {
        if (b[i].getAge() <= b[i - 1].getAge())
            assert(false);
    }
    for (int i = 1; i < b.size(); i++) {
        if (c[i].getName() <= b[i - 1].getName())
            assert(false);
    }
}


int main(){
    //TestSort();
    Main m;
    m.run();
}
