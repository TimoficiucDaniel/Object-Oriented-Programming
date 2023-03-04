#include "Estate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// to get rid of strcpy warnings
//_CRT_SECURE_NO_WARNINGS

Estate* createEstate(char* type, char* address, float surface, float price)
{
    Estate* E = malloc(sizeof(Estate));
    if(E == NULL)
        return NULL;
    E->type = malloc(sizeof (char)*(strlen(type)+1));
    if(E->type != NULL)
        strcpy(E->type, type);
    E->address = malloc(sizeof (char)*(strlen(address)-1));
    if(E->address != NULL)
        strcpy(E->address, address);
    E->surface = surface;
    E->price = price;

    return E;
}

void destroyEstate(Estate* E)
{
   // if(E == NULL)
        //return 1;

    free(E->type);
    free(E->address);
    free(E);
}

char* type(Estate* E)
{
    if (E == NULL)
        return 0;
    return E->type;
}

char* getAddress(Estate* E)
{
    if (E == NULL)
        return 0;
    return E->address;
}

float surface(Estate* E)
{
    if (E == NULL)
        return 0;
    return E->surface;
}

float price(Estate* E)
{
    if (E == NULL)
        return 0;
    return E->price;
}

int setType(Estate* E , char type[])
{
    if(E == NULL)
        return 0;
    strcpy(E->type, type);
    return 1;
}

int setAddress(Estate* E , char address[])
{
    if(E == NULL)
        return 0;
    strcpy(E->address, address);
    return 1;
}

int setSurface(Estate* E , float surface)
{
    if(E == NULL)
        return 0;
    E->surface = surface;
    return 1;
}

int setPrice(Estate* E , float price)
{
    if(E == NULL)
        return 0;
    E->price = price;
    return 1;
}