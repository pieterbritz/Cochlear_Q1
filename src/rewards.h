#ifndef __REWARDS_H__
#define __REWARDS_H__
#include <stdint.h>

typedef struct
{
    char customerId[4];
    char customerName[100];
    int totalSpend;
    int rewardPoints;
    char rewardTier;
} type_Customer;

typedef struct
{
    char customerId[4];
    int justSpent;
    int rewardAmount;
} type_purchase;

enum
{
    NONE,
    BRONSE,
    SILVER,
    GOLD,
    MAX_TIER
} TIER;

#define MAX_CUSOMERS 10

void initCustomers(void);
void setCustomerId(char customerIndex, char digit1, char digit2, char digit3, char digit4);
char * getCustomerId(char customerIndex);
char * getCustomerName(char customerIndex);
int getTotalSpend(char customerIndex);
int getRewardPoints(char customerIndex);
int getRewardTier(char customerIndex);
uint8_t getTotalCutomer(void);
void setTotalCutomer(uint8_t total);
void AddCustomer(char * customerName, char nameLength, uint16_t totalSpend, uint16_t rewardTier);
int FindCustomerIndex(char *name, char lenght);
void AddPurchase(char customerIndex, uint16_t purchases);

#endif // __REWARDS_H__