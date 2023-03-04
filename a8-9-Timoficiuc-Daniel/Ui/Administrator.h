#ifndef A5_6_ADMINISTRATOR_H
#define A5_6_ADMINISTRATOR_H

#include "../Service/Service.h"
#include "Ui.h"

class Administrator:public Ui{
    private:
        Service serv;
    public:

    Administrator();
    explicit Administrator(Service& serv);

    void show_menu()override;

    void addDog();

    void removeDog();

    void updateDog();

    void listAll();

    void run()override;

    void displayFile();

};
#endif //A5_6_ADMINISTRATOR_H
