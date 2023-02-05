#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h> 


#include "menu.h"

bool keepRunning = true;
static void GetCustomerData(menu_t *menuData, char customerIndex);

void DrawMenu(menu_t *menuData)
{
    char *str = {"Silver"};
    system("clear");
    printf("============================================================\n");
    printf("=  Cochlear Rewards v0.1                                   =\n");
    printf("============================================================\n");
    printf("=     Options:                                             =\n");
    printf("=     ========                                             =\n");
    printf("=     1. List Customers                                    =\n");
    printf("=     2. View Customer Info                                =\n");
    printf("=     3. Add Customer                                      =\n");
    printf("=     4. Add Purchase                                      =\n");
    printf("=                                                          =\n");
    printf("=     Customer ID [%d%d%d%d]                                   =\n", menuData->currentCustomer.customerId[0], menuData->currentCustomer.customerId[1], menuData->currentCustomer.customerId[2], menuData->currentCustomer.customerId[3]);
    printf("=     Total Perchases [$%d]                                =\n", menuData->currentCustomer.totalSpend);
    printf("=     Reward points [%d]                                   =\n", menuData->currentCustomer.rewardPoints);
    if (menuData->currentCustomer.rewardTier == BRONSE) str = "BRONSE";
    else if (menuData->currentCustomer.rewardTier == SILVER) str = "SILVER";
    else if (menuData->currentCustomer.rewardTier == GOLD) str = "GOLD";
    printf("=     Reward Tier [%s]                                     =\n", str);
    printf("=                                                          =\n");
    printf("=                                                          =\n");
    printf("============================================================\n");
 }

void DrawList(menu_t *menuData)
{
    int i;
    char *str = {"Silver"};
    system("clear");
    printf("============================================================\n");
    printf("=  Cochlear Rewards v0.1                                   =\n");
    printf("============================================================\n");
    printf("=     Options:                                             =\n");
    printf("=     ========                                             =\n");
    printf("=     1. List Customers                                    =\n");
    printf("=     2. View Customer Info                                =\n");
    printf("=     3. Add Customer                                      =\n");
    printf("=     4. Add Purchase                                      =\n");
    printf("=                                                          =\n");
    for(i = 0; i < MAX_CUSOMERS; i++)
    {
        GetCustomerData(menuData, i);
        printf("=     Customer ID [%d%d%d%d]                                =\n", menuData->currentCustomer.customerId[0], menuData->currentCustomer.customerId[1], menuData->currentCustomer.customerId[2], menuData->currentCustomer.customerId[3]);
        printf("=     Total Perchases [$%d]                            =\n", menuData->currentCustomer.totalSpend);
        printf("=     Reward points [%d]                              =\n", menuData->currentCustomer.rewardPoints);
        if (menuData->currentCustomer.rewardTier == BRONSE) str = "BRONSE";
        else if (menuData->currentCustomer.rewardTier == SILVER) str = "SILVER";
        else if (menuData->currentCustomer.rewardTier == GOLD) str = "GOLD";
        printf("=     Reward Tier [%s]                             =\n", str);
        printf("=                                                          =\n");
    }
    printf("=                                                          =\n");
    printf("============================================================\n");
 }

void drawMore(char *message)
{
    printf("%s", message);
}

int ListFiles(void)
{
  DIR *d;
  struct dirent *dir;
  d = opendir(".");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
  return(0);
}

static void GetCustomerData(menu_t *menuData, char customerIndex)
{
    memcpy(menuData->currentCustomer.customerId, getCustomerId(customerIndex), 4);
    menuData->currentCustomer.rewardPoints = getRewardPoints(customerIndex);
    menuData->currentCustomer.rewardTier = getRewardTier(customerIndex);
    menuData->currentCustomer.totalSpend = getTotalSpend(customerIndex);
}


// Menu implementation
void menu(menu_t *menuData)
{
    int command, res;
    char rxChar = '-';

    DrawMenu(menuData);
    while (keepRunning)
    {
        command = getchar();
        switch(command)
        {
        case '1':
            DrawList(menuData);
            printf("List Customers.\n");
            break;

        case '2':
            getchar();
            rxChar = '-';
            printf("Enter Customer Number: ");
            while (rxChar != '\n')
            {
                rxChar = getchar();
                printf("\nGot %d\n", rxChar);
                if (((rxChar - 0x30) > 0) && ((rxChar - 0x30) < 10))
                {
                    printf("\nGot %d, GetCustomerData()\n", rxChar);
                    GetCustomerData(menuData, rxChar - 0x31);
                }
                else if (rxChar == '\n')
                {
                    break;
                }
            }
            printf("\nGot %d\n", rxChar);
            
            DrawMenu(menuData);
            printf("View Customer Info.\n");
            break;

        case '3':
            printf("Add Customer.\n");
            break;

        case '4':
            DrawMenu(menuData);
            printf("Add Purchase.\n");
           break;

        case 'x':
        case 'X':
            printf("Quit\n");
            keepRunning = false;
            break;

        default:
            break;
        } // switch(command)
    } // while (keepRunning)
    
} // void menu(menu_t *menuData)