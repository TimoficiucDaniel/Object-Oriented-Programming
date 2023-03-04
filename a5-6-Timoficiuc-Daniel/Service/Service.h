#ifndef A5_6_SERVICE_H
#define A5_6_SERVICE_H
#include "../Repo/Database.h"
#include "../Domain/Dog.h"


class Service{
public:
        Service();
        Service(Database<Dog>& other);

        bool addDog(std::string name, std::string breed, int age, std::string link);
        bool removeDog(int id);
        bool updateDog(int option,int id,const std::string& item_to_change);
        Dog getCurrentDog();

    Database<Dog> database;
};

#endif //A5_6_SERVICE_H
