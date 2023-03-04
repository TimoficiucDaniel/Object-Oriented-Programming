#include "EstateRepo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"

EstateRepo* createRepo()
{
    EstateRepo* ER = (EstateRepo*)malloc(sizeof(EstateRepo));
    if(ER == NULL)
        return NULL;
    ER->estates = createDynamicArray(CAPACITY,&destroyEstate);

    return ER;
}

void destroyRepo(EstateRepo* ER)
{
    //if(ER == NULL)
        //return 0;
    destroy(ER->estates);
    free(ER);
}

int addEstateRepo(EstateRepo* ER,Estate* E )
{
    add(ER->estates,E);
    return 1;
}

int getLengthRepo(EstateRepo* ER )
{
    if (ER == NULL)
        return 0;

    return getLength(ER->estates);
}

Estate* findByName(EstateRepo* ER, char* address) {
    if (ER == NULL || address == NULL) {
        return NULL;
    }

    for (int i = 0; i < getLength(ER->estates); i++) {
        Estate* E = get(ER->estates, i);
        if (strcmp(getAddress(E), address) == 0) {
            return E;
        }
    }

    return NULL;
}

int deleteEstate(EstateRepo* ER, char* address )
{
    if (ER == NULL || address == NULL) {
        return -1;
    }
    Estate* E = findByName(ER,address);
    for (int i = 0; i < getLength(ER->estates); i++)

        if (get(ER->estates, i) == E)
        {
            delete(ER->estates, i);
            return 0;
        }
    return 1;

}
/*
int updateEstateTypeRepo(EstateRepo* ER, char type[] ,char address[])
{
    int position;
    position = findEstate(ER, address);
    if(position == -1)
        return 0;
    setType(ER->estates[position],type);
    return 1;
}

int updateEstateAddressRepo(EstateRepo* ER, char address[], char address2[]  )
{
    int position;
    position = findEstate(ER, address2);
    if(position == -1)
        return 0;
    setAddress(ER->estates[position],address);
    return 1;
}

int updateEstateSurfaceRepo(EstateRepo* ER, float surface, char address[]  )
{
    int position;
    position = findEstate(ER, address);
    if(position == -1)
        return 0;
    setSurface(ER->estates[position],surface);
    return 1;
}

int updateEstatePriceRepo(EstateRepo* ER, float price, char address[]  )
{
    int position;
    position = findEstate(ER, address);
    if(position == -1)
        return 0;
    setPrice(ER->estates[position],price);
    return 1;
}
*/