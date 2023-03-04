#pragma once
#include "EstateRepo.h"

typedef struct
{
    EstateRepo* repo;
}Service;

Service* createService(EstateRepo* ER);
void destroyService(Service* S);

int addEstate(Service* S, char* type , char* address, char* surface, char* price);

int deleteEstateServ(Service* S, char* address);

int updateEstateTypeServ(Service* S, char type[], char address[] );
int updateEstateAddressServ(Service* S, char address[], char address2[] );
int updateEstateSurfaceServ(Service* S, char surface[], char address[] );
int updateEstatePriceServ(Service* S, char price[], char address[] );

int validateType(char* type);
int validateSurface(char* surface);
int validatePrice(char* price);

int convertToFloat(char* string);

