#include "Service.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


Service* createService(EstateRepo* ER)
{
    Service* S = malloc(sizeof(Service));
    if(S == NULL)
        return NULL;
    S->repo = ER;
    return S;
}

void destroyService(Service* S)
{
    //if(S == NULL)
       // return NULL;
    destroyRepo(S->repo);
    free(S);
}

int validateType(char* type)
{
    if(strcmp(type,"house")!=0)
        if(strcmp(type,"penthouse")!=0)
            if(strcmp(type,"apartment")!=0)
                return 0;
    return 1;
}

int validateSurface(char* surface)
{
    int length = strlen(surface);
    for(int i = 0; i< length; i++)
        if(isdigit(surface[i])!=0)
            return 0;
    return 1;
}

int convertToFloat(char* string)
{
    int length = strlen(string);
    int number = 0;
    for(int i = 0 ;i < length; i++)
        number = number*10 + string[i];
    return number;
}

int validatePrice(char* price)
{
    int length = strlen(price);
    for(int i = 0; i< length; i++)
        if(isdigit(price[i])!=0)
            return 0;
    return 1;
}

int addEstate(Service* S, char* type , char* address, char* surface, char* price) {
    if (validateType(type) == 0)
        return 0;
    if (validateSurface(surface) == 0)
        return 0;

    float floatSurface;
    floatSurface = convertToFloat(surface);

    if (validatePrice(price) == 0)
        return 0;

    float floatPrice;
    floatPrice = convertToFloat(price);

    Estate* E = createEstate(type,address, floatSurface, floatPrice);
    return addEstateRepo(S->repo,E);

}

int deleteEstateServ(Service* S, char* address)
{

    return deleteEstate(S->repo, address);

}
/*
int updateEstateTypeServ(Service* S, char type[], char address[] )
{
    if(validateType(type)== 0)
        return 0;
    int flag;
    flag = updateEstateTypeRepo(S->repo,type, address);
    if(flag == 0)
        return 0;
    return 1;
}

int updateEstateAddressServ(Service* S, char address[], char address2[] )
{
    int flag;
    flag = updateEstateAddressRepo(S->repo,address,address2);
    if(flag == 0)
        return 0;
    return 1;
}

int updateEstateSurfaceServ(Service* S, char surface[] , char address[] ) {
    if (validateSurface(surface) == 0)
        return 0;
    int flag;
    float floatSurface;
    floatSurface = convertToFloat(surface);
    flag = updateEstateSurfaceRepo(S->repo, floatSurface, address);
    if (flag == 0)
        return 0;
    return 1;
}

int updateEstatePriceServ(Service* S, char price[] , char address[] ) {
    if (validatePrice(price) == 0)
        return 0;
    int flag;
    float floatPrice;
    floatPrice = convertToFloat(price);
    flag = updateEstateSurfaceRepo(S->repo, floatPrice, address);
    if (flag == 0)
        return 0;
    return 1;
}


*/