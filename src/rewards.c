/*
* 		main.c - Cochlear Rewards
*		Author: Pieter Britz
*		Date: 04 Febuary 2023
*
*       

*
*/
#include <stdint.h>
#include "rewards.h"


type_Customer customer[MAX_CUSOMERS];
type_purchase purchase;
uint8_t totalCustomers;

static void setCustomerId(char customerIndex, char digit1, char digit2, char digit3, char digit4)
{
    customer[customerIndex].customerId[0] = digit1;
    customer[customerIndex].customerId[1] = digit2;
    customer[customerIndex].customerId[2] = digit3;
    customer[customerIndex].customerId[3] = digit4;
}

char * getCustomerId(char customerIndex)
{
    if (customerIndex < totalCustomers)
        return customer[customerIndex].customerId;
    else
        return -1;    
}

uint8_t getTotalCutomer(void)
{
    return totalCustomers;
}

void setTotalCutomer(uint8_t total)
{
    totalCustomers = total;
}

static void setTotalSpend(char customerIndex, uint16_t spend)
{
    customer[customerIndex].totalSpend = spend;
}

int getTotalSpend(char customerIndex)
{
    if (customerIndex < totalCustomers)
        return customer[customerIndex].totalSpend;
    else
        return -1;    
}

static void setRewardPoints(char customerIndex, uint16_t points)
{
    customer[customerIndex].rewardPoints = points;
}

int getRewardPoints(char customerIndex)
{
    if (customerIndex < totalCustomers)
        return customer[customerIndex].rewardPoints;
    else
        return -1;    
}


static void setRewardTier(char customerIndex, uint16_t tier)
{
    customer[customerIndex].rewardTier = tier;
}

int getRewardTier(char customerIndex)
{
    if (customerIndex < totalCustomers)
        return customer[customerIndex].rewardTier;
    else
        return -1;
}

void initCustomers(void)
{
    setCustomerId(0, 0, 0, 0, 1);
    setTotalSpend(0, 1200);
    setRewardPoints(0, customer[0].totalSpend * SILVER);
    setRewardTier(0, SILVER);

    setCustomerId(1, 0, 0, 0, 2);
    setTotalSpend(1, 800);
    setRewardPoints(1, customer[0].totalSpend * BRONSE);
    setRewardTier(1, BRONSE);

    setCustomerId(2, 0, 0, 0, 3);
    setTotalSpend(2, 10124);
    setRewardPoints(2, customer[0].totalSpend * GOLD);
    setRewardTier(2, GOLD);

    setCustomerId(3, 0, 0, 0, 4);
    setTotalSpend(3, 1200);
    setRewardPoints(3, customer[0].totalSpend * SILVER);
    setRewardTier(3, SILVER);

    setCustomerId(4, 0, 0, 0, 5);
    setTotalSpend(4, 123);
    setRewardPoints(4, customer[0].totalSpend * BRONSE);
    setRewardTier(4, BRONSE);

    totalCustomers = 5;
}

void AddCustomer(int totalSpend, int rewardPoints, int rewardTier)
{

}

// End of file