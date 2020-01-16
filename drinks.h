//
// Created by edian on 17.12.2019.
//

#ifndef FOOD_ORDERING_DRINKS_H
#define FOOD_ORDERING_DRINKS_H

#include <stdio.h>
typedef struct _drink{
    char * name;
    double price;
}drink;
void readDrinks(int *nrDrinksAddr,drink ** drinkAddr,FILE * data);
void displayDrinks(char * foodType,int nrDrinks, drink * d);
void freeDrinks(int nrDrinks,drink * d);
#endif //FOOD_ORDERING_DRINKS_H
