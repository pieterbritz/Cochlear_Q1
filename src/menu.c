#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h> 
#include "logger.h"

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
    printf("=     Customer ID     [%d%d%d%d]                                   =\n", menuData->currentCustomer.customerId[0], menuData->currentCustomer.customerId[1], menuData->currentCustomer.customerId[2], menuData->currentCustomer.customerId[3]);
    printf("=     Customer Name   [%s]                            =\n", menuData->currentCustomer.customerName);
    printf("=     Total Perchases [$%d]                                =\n", menuData->currentCustomer.totalSpend);
    printf("=     Reward points   [%d]                                   =\n", menuData->currentCustomer.rewardPoints);
    if (menuData->currentCustomer.rewardTier == BRONSE) str = "BRONSE";
    else if (menuData->currentCustomer.rewardTier == SILVER) str = "SILVER";
    else if (menuData->currentCustomer.rewardTier == GOLD) str = "GOLD";
    printf("=     Reward Tier     [%s]                                     =\n", str);
    printf("=                                                          =\n");
    printf("=                                                          =\n");
    printf("============================================================\n");
 }

void DrawList(menu_t *menuData)
{
    int i;
    char *str = {"None"};
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
    for(i = 0; i < getTotalCutomer(); i++)
    {
        GetCustomerData(menuData, i);
        printf("=     Customer ID     [%d%d%d%d]                           =\n", menuData->currentCustomer.customerId[0], menuData->currentCustomer.customerId[1], menuData->currentCustomer.customerId[2], menuData->currentCustomer.customerId[3]);
        printf("=     Customer Name   [%s]                            =\n", menuData->currentCustomer.customerName);
        printf("=     Total Perchases [$%d]                            =\n", menuData->currentCustomer.totalSpend);
        printf("=     Reward points   [%d]                              =\n", menuData->currentCustomer.rewardPoints);
        if (menuData->currentCustomer.rewardTier == BRONSE) str = "BRONSE";
        else if (menuData->currentCustomer.rewardTier == SILVER) str = "SILVER";
        else if (menuData->currentCustomer.rewardTier == GOLD) str = "GOLD";
        printf("=     Reward Tier     [%s]                             =\n", str);
        printf("=                                                          =\n");
    }
    printf("=                                                          =\n");
    printf("============================================================\n");
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
    memcpy(menuData->currentCustomer.customerId, getCustomerId(customerIndex), sizeof(getCustomerId(customerIndex)));
    sprintf(menuData->currentCustomer.customerName, "%s", getCustomerName(customerIndex));
    menuData->currentCustomer.rewardPoints = getRewardPoints(customerIndex);
    menuData->currentCustomer.rewardTier = getRewardTier(customerIndex);
    menuData->currentCustomer.totalSpend = getTotalSpend(customerIndex);
}


// Menu implementation
void menu(menu_t *menuData)
{
	char tmpBuff[130];
    int command, res;
    int rxChar;
    char name[50];
    int purchases;
    int tier;

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
            printf("Enter Customer Number: ");
            scanf("%d", &rxChar);
            if ((rxChar > 0) && (rxChar <= getTotalCutomer()))
            {
                GetCustomerData(menuData, rxChar - 1);
                sprintf(tmpBuff, "GetCustomerData: name[%s], Id[%s]", getCustomerName(rxChar - 1), getCustomerId(rxChar - 1));
                logger(__FUNCTION__, tmpBuff);
            }
            DrawMenu(menuData);
            printf("View Customer Info.\n");
            break;

        case '3':
            getchar();
            rxChar = '-';
            printf("Add Customer ");
            printf("Enter new customer name: ");
            scanf("%s", name);
            printf("Enter any new customer purschases: ");
            scanf("%d", &purchases);
            printf("Enter new customer's reward tier: ");
            scanf("%d", &tier);
            AddCustomer(name, sizeof(name), purchases, tier);
            DrawMenu(menuData);
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