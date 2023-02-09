/*
 * test_rewards.c
 *
 *  Created on: Feb 6, 2023
 *      Author: Pieter Britz
 */

#include <np.h>
#include <stdio.h>
#include "rewards.h"

extern type_Customer customer[MAX_CUSOMERS];

static int setup(void)
{
	return 0;
}

static int teardown(void)
{
	return 0;
}

static void test_setCustomerId(void)
{
    setCustomerId(0, 1, 2, 3, 4);
    NP_ASSERT_EQUAL(customer[0].customerId[0], 1);
    NP_ASSERT_EQUAL(customer[0].customerId[1], 2);
    NP_ASSERT_EQUAL(customer[0].customerId[2], 3);
    NP_ASSERT_EQUAL(customer[0].customerId[3], 4);
}

static void test_getCustomerId(void)
{
    char data[4];

    setCustomerId(1, 9, 8, 7, 6);
    memcpy(data, getCustomerId(1), 4);

    NP_ASSERT_EQUAL(data[0], 9);
    NP_ASSERT_EQUAL(data[1], 8);
    NP_ASSERT_EQUAL(data[2], 7);
    NP_ASSERT_EQUAL(data[3], 6);
}

static void test_getCustomerName(void)
{
    char customerIndex = 1;
    char name[100];

    memcpy(customer[1].customerName, "Bernard", sizeof("Bernard"));
    memcpy(name, getCustomerName(customerIndex), 7);
    NP_ASSERT_STR_EQUAL(customer[1].customerName, name);
}

/*
int getTotalSpend(char customerIndex);
int getRewardPoints(char customerIndex);
int getRewardTier(char customerIndex);
uint8_t getTotalCutomer(void);
void setTotalCutomer(uint8_t total);
void AddCustomer(char * customerName, char nameLength, uint16_t totalSpend, uint16_t rewardTier);
*/
