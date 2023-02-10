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
    setCustomerId(1, 9, 8, 7, 6);

    NP_ASSERT_EQUAL(customer[1].customerId[0], 9);
    NP_ASSERT_EQUAL(customer[1].customerId[1], 8);
    NP_ASSERT_EQUAL(customer[1].customerId[2], 7);
    NP_ASSERT_EQUAL(customer[1].customerId[3], 6);
}

static void test_getCustomerName(void)
{
    char customerIndex = 1;
    char name[100];

    memcpy(customer[customerIndex].customerName, "Bernard", sizeof("Bernard"));
    snprintf(name, 8, "%s", getCustomerName(customerIndex));
    NP_ASSERT_STR_EQUAL(customer[customerIndex].customerName, name);
}

static void test_spending(void)
{
    customer[2].customerId[0] = 4;
    customer[2].customerId[0] = 5;
    customer[2].customerId[0] = 6;
    customer[2].customerId[0] = 7;
    customer[2].rewardPoints = 400;
    customer[2].totalSpend = 200;
    customer[2].rewardTier = 2;
    setTotalCutomer(3);

    NP_ASSERT_EQUAL(getTotalSpend(2), 200);
    NP_ASSERT_EQUAL(getRewardPoints(2), 400);
    NP_ASSERT_EQUAL(getRewardTier(2), 2);
}

static void test_totalCustomers(void)
{
    setTotalCutomer(6);
    NP_ASSERT_EQUAL(getTotalCutomers(), 6);
}

static void test_addCustomer(void)
{
    setTotalCutomer(0);
    AddCustomer("John", 5, 200, 3);
    NP_ASSERT_EQUAL(customer[0].customerId[0], 0);
    NP_ASSERT_EQUAL(customer[0].customerId[1], 0);
    NP_ASSERT_EQUAL(customer[0].customerId[2], 0);
    NP_ASSERT_EQUAL(customer[0].customerId[3], 1);
    NP_ASSERT_STR_EQUAL(customer[0].customerName, "John");
    NP_ASSERT_EQUAL(customer[0].totalSpend, 200);
    NP_ASSERT_EQUAL(customer[0].rewardTier, 3);
    NP_ASSERT_EQUAL(customer[0].rewardPoints, 600);
}

/*
void AddCustomer(char * customerName, char nameLength, uint16_t totalSpend, uint16_t rewardTier);
*/
