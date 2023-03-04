#ifndef A5_6_SAVETOCSV_H
#define A5_6_SAVETOCSV_H

#include "Database.h"
#include "fstream"

/**
 * derived class of the repo class
 */
class CSV: public Database<Dog>{
public:
    CSV()=default;
    CSV(Database<Dog>& d){
        this->elements = d.getElems();
    }
    /**
     * override function that stores the repo into a csv file using the csv format
     */
    void storeToFile() override {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (auto d: this->getElems())
                file << d;
            file.close();
        }
    }
    /**
     * opens the csv file in notepad
     */
    void display() override{
        std::string command= "notepad.exe "+filename;
        system(command.c_str());
    }
};

#endif //A5_6_SAVETOCSV_H
