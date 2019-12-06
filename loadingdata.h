//
// Created by edian on 07.12.2019.
//

#ifndef FOOD_ORDERING_LOADINGDATA_H
#define FOOD_ORDERING_LOADINGDATA_H
#include <stdio.h>
void readNoOf(int * noOf, FILE * data);
void readFood(char ** foodTypes,int nrOfFoodTypes,int * nrSpecType,char *** specFoods,double **priceFoods,
              FILE * data);
void readDrinks(int nrDrinks,char **drinks,double *pricesDrinks,FILE * data);
#endif //FOOD_ORDERING_LOADINGDATA_H
