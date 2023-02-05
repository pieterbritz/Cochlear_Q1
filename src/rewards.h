#ifndef __REWARDS_H__
#define __REWARDS_H__

typedef struct
{
    char customerId[4];
    char cusomerName[100];
    int totalSpend;
    int rewardPoints;
    int rewardTier;
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
    GOLD
} TIER;

#define MAX_CUSOMERS 10

void initCustomers(void);
char * getCustomerId(char customerIndex);
int getTotalSpend(char customerIndex);
int getRewardPoints(char customerIndex);
int getRewardTier(char customerIndex);

#endif // __REWARDS_H__