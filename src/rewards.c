/*
* 		main.c - Cochlear Rewards
*		Author: Pieter Britz
*		Date: 04 Febuary 2023
*
*       

*
*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "rewards.h"
#include "logger.h"


type_Customer customer[MAX_CUSOMERS];
type_purchase purchase;
uint8_t totalCustomers;

void setCustomerId(char customerIndex, char digit1, char digit2, char digit3, char digit4)
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
        return NULL;    
}

static void setCustomerName(char customerIndex, char * name, char length)
{
    char tmpBuff[150];
    if ((name != NULL) && (length < sizeof(customer[customerIndex].customerName)))
    {
            sprintf(tmpBuff, "customerIndex[%d], name[%s], length[%d]", customerIndex, name, length);
            logger(__FUNCTION__, tmpBuff);
            memcpy(customer[customerIndex].customerName, name, length);
    }
}

char * getCustomerName(char customerIndex)
{
 	char tmpBuff[150];
    sprintf(tmpBuff, "customerIndex[%d], customerName[%s]", customerIndex, customer[customerIndex].customerName);
    logger(__FUNCTION__, tmpBuff);
    return customer[customerIndex].customerName;
}

void setTotalCutomer(uint8_t total)
{
    totalCustomers = total;
}

uint8_t getTotalCutomer(void)
{
 	char tmpBuff[130];
    sprintf(tmpBuff, "totalCustomers[%d]", totalCustomers);
    logger(__FUNCTION__, tmpBuff);
    return totalCustomers;
}

static void setTotalSpend(char customerIndex, uint16_t spend)
{
 	char tmpBuff[130];
    sprintf(tmpBuff, "customerIndex[%d], spend[%d]", customerIndex, spend);
    logger(__FUNCTION__, tmpBuff);
    customer[customerIndex].totalSpend = spend;
}

int getTotalSpend(char customerIndex)
{
 	char tmpBuff[130];
    sprintf(tmpBuff, "customerIndex[%d], totalSpend[%d]", customerIndex, customer[customerIndex].totalSpend);
    logger(__FUNCTION__, tmpBuff);
    if (customerIndex < totalCustomers)
        return customer[customerIndex].totalSpend;
    else
        return -1;    
}

static void setRewardPoints(char customerIndex, uint32_t points)
{
 	char tmpBuff[130];
    sprintf(tmpBuff, "customerIndex[%d], points[%d]", customerIndex, points);
    logger(__FUNCTION__, tmpBuff);
    customer[customerIndex].rewardPoints = points;
}

int getRewardPoints(char customerIndex)
{
 	char tmpBuff[130];
    sprintf(tmpBuff, "customerIndex[%d], rewardPoints[%d]", customerIndex, customer[customerIndex].rewardPoints);
    logger(__FUNCTION__, tmpBuff);
    if (customerIndex < totalCustomers)
        return customer[customerIndex].rewardPoints;
    else
        return -1;    
}

static void setRewardTier(char customerIndex, char tier)
{
 	char tmpBuff[130];
    sprintf(tmpBuff, "customerIndex[%d], tier[%d]", customerIndex, tier);
    logger(__FUNCTION__, tmpBuff);
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
    setCustomerName(0, "John Carter", 11);
    setTotalSpend(0, 120);
    setRewardPoints(0, customer[0].totalSpend * SILVER);
    setRewardTier(0, SILVER);

    setCustomerId(1, 0, 0, 0, 2);
    setCustomerName(1, "Will Smith", 10);
    setTotalSpend(1, 80);
    setRewardPoints(1, customer[1].totalSpend * BRONSE);
    setRewardTier(1, BRONSE);

    setCustomerId(2, 0, 0, 0, 3);
    setCustomerName(2, "Steven Seagal", 13);
    setTotalSpend(2, 1012);
    setRewardPoints(2, customer[2].totalSpend * GOLD);
    setRewardTier(2, GOLD);

    setCustomerId(3, 0, 0, 0, 4);
    setCustomerName(3, "Alex Von Brasch", 15);
    setTotalSpend(3, 170);
    setRewardPoints(3, customer[3].totalSpend * SILVER);
    setRewardTier(3, SILVER);

    setCustomerId(4, 0, 0, 0, 5);
    setCustomerName(4, "Orlando Wu", 10);
    setTotalSpend(4, 12);
    setRewardPoints(4, customer[4].totalSpend * BRONSE);
    setRewardTier(4, BRONSE);

    totalCustomers = 5;
}

void AddCustomer(char * customerName, char nameLength, uint16_t totalSpend, uint16_t rewardTier)
{
    if (getTotalCutomer() < 10)
        setCustomerId(getTotalCutomer(), 0, 0, 0, getTotalCutomer() + 1);
    else if (getTotalCutomer() < 100)
        setCustomerId(getTotalCutomer(), 0, 0, getTotalCutomer() / 10, (getTotalCutomer() % 10) + 1);
    setCustomerName(getTotalCutomer(), customerName, nameLength);
    setRewardTier(getTotalCutomer(), rewardTier);
    setTotalSpend(getTotalCutomer(), totalSpend);
    if (rewardTier < MAX_TIER)
        setRewardPoints(getTotalCutomer(), totalSpend * rewardTier);
    else
        printf("error: Incorrect reward tier!\n");
    setTotalCutomer(getTotalCutomer() + 1);
}

// End of file