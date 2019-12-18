//
// Created by edian on 05.11.2019.
//
#ifndef FOOD_ORDERING_DISPLAY_H
#define FOOD_ORDERING_DISPLAY_H
#define MAX_CUTLERY_NAME 20
#include "userdata.h"
#include "specFoods.h"
#include "drinks.h"
void displayCutlery(char cutlery[][MAX_CUTLERY_NAME]);
void displayAddInfo(char addinfo[],int *state);
void displayOrder(specFood *s,drink * d,char cutlery[],char addinfo[],userdata *u);
#endif //FOOD_ORDERING_DISPLAY_H
