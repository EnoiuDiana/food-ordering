//
// Created by edian on 05.11.2019.
//

#ifndef FOOD_ORDERING_DISPLAY_H
#define FOOD_ORDERING_DISPLAY_H

#define MAX_FOOD_TYPE_NAME 100
#define MAX_SPEC_TYPE_NAME 300
#define MAX_CUTLERY_NAME 20
#define MAX_DRINK_NAME 50

void displayFoodTypes(int nrOfFoodTypes,char ** foodTypes);
void displaySpecificFoods(int nrSpecType,char * foodType,char ** specTypes,double * prices);
void displayDrinks(char * foodType,int nrDrinks,char ** drinks,
                   double * pricesDrinks);
void displayCutlery(char cutlery[][MAX_CUTLERY_NAME]);
void displayAddInfo(char addinfo[],int *state);
void displayOrder(char * specType,double price,char * drink,double priceDrink,
                  char cutlery[],char addinfo[],char username[]);

#endif //FOOD_ORDERING_DISPLAY_H
