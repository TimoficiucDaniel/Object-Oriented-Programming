#ifndef A5_6_SAVETOHTML_H
#define A5_6_SAVETOHTML_H

#include "Database.h"
#include "fstream"
#include "string"
#include "iostream"
#include <Windows.h>
#include <shellapi.h>

/**
 * derived class of the database class
 */
class HTML: public Database<Dog> {
public:
    HTML()=default;
    HTML(Database<Dog>& d){
        this->elements =  d.getElems();
    }

    /**
     * stores the repo into a html file using html so it can be opened as a table in browser
     */
    void storeToFile()override {
        std::ofstream file(filename);

        if (file.is_open()) {
            file<< "<!DOCTYPE html><html><head><title>Dog Shelter</title></head><body><table border = ""1""><tr><td>Breed</td><td>Name</td><td>Age</td><td>Link</td><td>Id</td></tr>\n";
            for (Dog dog: this->elements) {
                file << "<tr>\n";
                file << "<td>\n";
                file << dog.getBreed();
                file << "\n</td>\n";
                file << "<td>\n";
                file << dog.getName();
                file << "\n</td>\n";
                file << "<td>\n";
                file << dog.getAge();
                file << "\n</td>\n";
                file << "<td>\n<a href = """;
                file << dog.getLink_to_photo();
                file << """>\n" << dog.getLink_to_photo() << "\n</a>\n</td>\n";
                file << "<td>\n";
                file << dog.getId();
                file << "\n</td>\n";
                file << "</tr>\n";
            }
            file << "</table></body></td></tr></html>";

            file.close();
        }
    }

    /**
     * opens the html file with the browser
     */
    void display()override{
        const char* c = filename.c_str();
        ShellExecuteA(nullptr, "open", c, nullptr, nullptr,
                      SW_SHOWMAXIMIZED);
    }
};

#endif //A5_6_SAVETOHTML_H
