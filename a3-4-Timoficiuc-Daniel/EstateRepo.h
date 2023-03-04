#pragma once
#include "Estate.h"
#include "DynamicArray.h"

typedef struct
{
    DynamicArray* estates;
}EstateRepo;

// crate and destroy Repo
EstateRepo* createRepo();
void destroyRepo(EstateRepo* ER);

Estate* findByName(EstateRepo* ER, char* address);

// functions
int addEstateRepo(EstateRepo* ER,Estate* E );
int getLengthRepo(EstateRepo* ER );
int deleteEstate(EstateRepo* ER, char* address );
/*int updateEstateTypeRepo(EstateRepo* ER, char type[] , char address[]  );
int updateEstateAddressRepo(EstateRepo* ER, char address[], char address2[]  );
int updateEstateSurfaceRepo(EstateRepo* ER, float surface , char address[] );
int updateEstatePriceRepo(EstateRepo* ER, float price , char address[] );
*/