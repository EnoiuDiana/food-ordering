//
// Created by edian on 07.12.2019.
//

#ifndef FOOD_ORDERING_LOADINGDATA_H
#define FOOD_ORDERING_LOADINGDATA_H
#include <stdio.h>
void readFood(char *** foodTypesAddr,int *nrOfFoodTypesAddr,int ** nrSpecTypeAddr,char **** specFoodsAddr,double ***priceFoodsAddr,
              FILE * data);
void readDrinks(int *nrDrinksAddr,char ***drinksAddr,double **pricesDrinksAddr,FILE * data);
void freeData(int nrOfFoodTypes,int *nrSpecType,char ***specFoods,char **foodTypes,double **priceFoods,int nrDrinks,
              char **drinks,double *pricesDrinks);
#endif //FOOD_ORDERING_LOADINGDATA_H
