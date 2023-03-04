#ifndef A5_6_ADMINISTRATOR_H
#define A5_6_ADMINISTRATOR_H

#include "../Service/Service.h"

class Administrator{
    private:
        Service serv;
    public:

    Administrator();
    explicit Administrator(Service& serv);

    static void show_menu();

    void addDog();

    void removeDog();

    void updateDog();

    void listAll();

    void run();

    bool validateInteger(const std::string& age);
};
#endif //A5_6_ADMINISTRATOR_H
