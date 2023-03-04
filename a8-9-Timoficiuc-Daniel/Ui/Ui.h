
#ifndef A5_6_UI_H
#define A5_6_UI_H
#include <string>
#include "UiValidators.h"

class Ui {
protected:
    UiValidator v;

public:

    virtual void run() = 0;

    virtual void show_menu() = 0;

};



#endif //A5_6_UI_H
