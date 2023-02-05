
#ifndef __MENU_H__
#define __MENU_H__

#include <stdio.h>
#include <stdint.h>
#include "rewards.h"

typedef struct menu_t
{
    type_Customer currentCustomer;
} menu_t;


void menu(menu_t *menuData);
void DrawMenu(menu_t *menuData);
void drawMore(char *message);



#endif // __MENU_H__