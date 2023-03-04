#pragma once
#include "Service.h"

typedef struct
{
    Service* serv;
}Ui;

Ui* createUi(Service* S);
void destroyUi(Ui* ui);

void startUi(Ui* ui);