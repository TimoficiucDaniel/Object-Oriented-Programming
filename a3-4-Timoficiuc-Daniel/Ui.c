#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Ui.h"
#include "Service.h"

Ui* createUi(Service* S)
{
    Ui* ui = malloc(sizeof (Ui));
    if(ui == NULL)
        return NULL;
    ui->serv = S;

    return ui;

}

void destroyUI(Ui* ui)
{
    //if(ui == NULL)
        //return NULL;
    destroyService(ui->serv);
    free(ui);
}

void print_menu()
{
    printf("\n**********************************************************\n");
    printf("1 - add an estate.\n");
    printf("2 - delete an estate.\n");
    printf("3 - update an estate.\n");
    printf("4 - display all estates whose addresses contain a certain string, sorted by their price");
    printf("0 - to exit.\n");
    printf("**********************************************************\n");
}

int valid_command(int command)
{
    if(command >= 0 && command <=3)
        return 1;
    return 0;
}

void readStringWithSpaces(const char* message, int maxStrSize, char str[])
{
    printf(message);
    fgets(str, maxStrSize, stdin);
    // the newline is also read so we must eliminate it from the string
    size_t size = strlen(str) - 1;
    if (str[size] == '\n')
        str[size] = '\0';
}

int addEstateUi(Ui* ui)
{
    char type[50],address[50],price[50],surface[50];
    fgetc(stdin);
    readStringWithSpaces("Input the type: ", 50, type);
    readStringWithSpaces("Input the address: ", 50, address);
    printf("Input the surface:\n");
    readStringWithSpaces("Input the surface: ", 50, surface);
    readStringWithSpaces("Input the price: ", 50, price);

    return addEstate(ui->serv,type,address,surface, price);
}

int deleteEstateUi(Ui* ui)
{
    char address[50];
    fgetc(stdin);
    readStringWithSpaces("Input address of estate to delete: ",50,address);
    return deleteEstateServ(ui->serv,address);
}
/*
int updateEstateUi(Ui* ui)
{
    int option;
    char address[50];
    printf("Input address to update by.\n");
    scanf("%s",&address);
    printf("Input 1 to update type.\n");
    printf("Input 2 to update address.\n");
    printf("Input 3 to update surface.\n");
    printf("Input 4 to update price.\n");
    printf("Input 5 to exit.\n");
    scanf("%d",&option);
    if(option < 1 && option > 5)
    {
        printf("invalid input.\n");
        return 0;
    }
    else
        if(option == 1)
        {
            char type[50];
            printf("Input new type.\n");
            scanf("%s",&type);
            int flag = updateEstateTypeServ(ui->serv,type,address);
            return flag;
        }
        else
            if(option == 2)
            {
                char address2[50];
                printf("Input new address.\n");
                scanf("%s",&address2);
                int flag = updateEstateTypeServ(ui->serv,address2,address);
                return flag;
            }
            else
                if(option == 3)
                {
                    char surface[50];
                    printf("Input new surface.\n");
                    scanf("%s",&surface);
                    int flag = updateEstateTypeServ(ui->serv,surface,address);
                    return flag;
                }
                else
                    if(option == 4)
                    {
                        char price[50];
                        printf("Input new price.\n");
                        scanf("%s", &price);
                        int flag = updateEstateTypeServ(ui->serv, price, address);
                        return flag;
                    }
                    else
                        if(option == 5)
                            return 1;
}
*/
int readIntegerNumber(const char* message)
{
    char s[16];
    int res = 0;
    int flag = 0;
    int r = 0;

    while (flag == 0)
    {
        printf(message);
        scanf("%s", s);

        r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
        flag = (r == 1);
        if (flag == 0)
            printf("Error reading number!\n");
    }
    return res;
}

void startUi(Ui* ui)
{
    while(1)
    {
        print_menu();
        int command = readIntegerNumber("Input command: \n ");
        while(valid_command(command)==0)
        {
            printf("Invalid input.\n");
            printf("Try again.\n");
        }
        if(command == 1)
            {
                int flag = addEstateUi(ui);
                if(flag == 0)
                    printf("Error in adding estate due to input.\n");
            }
            else
                if(command == 2)
                {
                    int flag = deleteEstateUi(ui);
                    if(flag == 0)
                        printf("Error deleting estate due to address given.\n");
                }
                else
                    if(command == 3)
                    {
                        //int flag = updateEstateUi(ui);
                       // if(flag== 0)
                            printf("Error updating estate due to input.\n");
                    }
                    else
                        if(command == 0)
                            break;
                        else
                            if(command == 4)
                                break;
    }
}