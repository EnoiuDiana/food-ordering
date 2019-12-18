//
// Created by edian on 07.12.2019.
//

#ifndef FOOD_ORDERING_FOODTYPES_H
#define FOOD_ORDERING_FOODTYPES_H
#include <stdio.h>
#include "specFoods.h"
typedef struct _foodType{
    char * name;
    int noOfSpecType;
    specFood * specType;
}foodType;
void readFoodTypes(char **foodTypeAddr,int *noOfSpecTypesAddr,char *pt);
void readFood(foodType**foodTypeAddr, int *nrOfFoodTypesAddr, FILE * data);
void displayFoodTypes(int nrOfFoodTypes,foodType * foodTypes);
void freeFoodType(int nrOfFoodTypes,foodType * foodTypes);
#endif //FOOD_ORDERING_FOODTYPES_H
