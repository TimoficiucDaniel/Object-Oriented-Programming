#ifndef A5_6_SERVICE_H
#define A5_6_SERVICE_H

#include "SaveToHTML.h"
#include "Dogs.h"
#include "SaveToCSV.h"
#include "UndoRedo.h"


class Service{
public:
        Service();
        Service(Database<Dog>* other);

        void addDog(std::string name, std::string breed, int age, std::string link);

        void removeDog(int id);

        void updateDog(int id,Dog& d);

        Dog getCurrentDog();

        int getSize();

        Dog getDog(int index);

        void openFile();

        std::vector<Dog> getDogs();

        void undo();

        void redo();

    Database<Dog>* database;
    CommandManager* manager;
};

#endif //A5_6_SERVICE_H
