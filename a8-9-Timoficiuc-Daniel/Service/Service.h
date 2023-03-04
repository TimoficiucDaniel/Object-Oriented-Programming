#ifndef A5_6_SERVICE_H
#define A5_6_SERVICE_H

#include "../Repo/SaveToHTML.h"
#include "../Domain/Dog.h"
#include "../Repo/SaveToCSV.h"


class Service{
public:
        Service();
        Service(Database<Dog>* other);

        void addDog(std::string name, std::string breed, int age, std::string link);

        void removeDog(int id);

        void updateDog(int option,int id,const std::string& item_to_change);

        Dog getCurrentDog();

        int getSize();

        Dog getDog(int index);

        void openFile();

    Database<Dog>* database;
};

#endif //A5_6_SERVICE_H
