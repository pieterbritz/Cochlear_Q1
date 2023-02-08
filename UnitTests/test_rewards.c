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
