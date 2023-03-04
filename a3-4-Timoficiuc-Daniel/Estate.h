#pragma once

typedef struct
{
    char* type;
    char* address;
    float surface;
    float price;
}Estate;

// create and destroy functions
Estate* createEstate(char* type, char* address, float surface, float price);
void destroyEstate(Estate* E);

// getters for attributes
char* type(Estate* E);
char* getAddress(Estate* E);
float surface(Estate* E);
float price(Estate* E);

// setters
int setType(Estate* E, char type[]);
int setAddress(Estate* E, char address[]);
int setSurface(Estate* E, float surface);
int setPrice(Estate* E, float price);
