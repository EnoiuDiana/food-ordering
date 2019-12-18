//
// Created by edian on 07.12.2019.
//

#ifndef FOOD_ORDERING_FOODTYPES_H
#define FOOD_ORDERING_FOODTYPES_H
#include <stdio.h>
#include "specFoods.h"
void readFoodTypes(char **foodTypeAddr,int *noOfSpecTypesAddr,char *pt);
void readFood(specFood *** specFoodAddr,char *** foodTypeAddr, int *nrOfFoodTypesAddr, int ** noOfSpecTypesAddr, FILE * data);
void displayFoodTypes(int nrOfFoodTypes,char ** foodTypes);
void freeFoodType(int nrOfFoodTypes,char **foodType);
#endif //FOOD_ORDERING_FOODTYPES_H
