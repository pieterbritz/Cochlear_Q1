/*
* 		main.c - Cochlear Rewards
*		Author: Pieter Britz
*		Date: 04 Febuary 2023
*
*		The is the interface to a module that keeps track of
*		customer reward points.
*		
*/

#include <stdio.h>
#include <string.h>	//strlen
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>

#include "logger.h"
#include "menu.h"
#include "rewards.h"

menu_t menuData;


void main(void)
{
    printf("Welcome to the Cochlear Rewards v0.1\r\n");
    initCustomers();

	// Draw the menu
    menu(&menuData);

}
