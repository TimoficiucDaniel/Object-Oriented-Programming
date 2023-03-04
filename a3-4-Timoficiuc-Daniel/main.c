#include <stdio.h>
#include "Service.h"
#include "Ui.h"
//lab work add new item to menu that displays everything sorted by an attribute

int main()
{

    EstateRepo* repo = createRepo();
    Service* serv = createService(repo);

    Ui* ui = createUi(serv);

    startUi(ui);

    destroyUi(ui);

}

