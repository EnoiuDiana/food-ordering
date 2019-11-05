//
// Created by edian on 05.11.2019.
//

#ifndef FOOD_ORDERING_DISPLAY_H
#define FOOD_ORDERING_DISPLAY_H
#define MAX_FOOD_TYPE_NAME 10
#define MAX_SPEC_TYPE_NAME 100
#define MAX_NR_SPEC_TYPES 4
#define MAX_NR_PRICES 4
#define MAX_DR_CUT_NAME 15
void displayFoodTypes(int nrOfFoodTypes,char foodTypes[][MAX_FOOD_TYPE_NAME]);
void displaySpecificFoods(int nrSpecType[],int typeChoice,char foodTypes[][MAX_FOOD_TYPE_NAME],
                          char specTypes[][MAX_NR_SPEC_TYPES][MAX_SPEC_TYPE_NAME],int prices[][MAX_NR_PRICES]);
void displayDrinks(char foodTypes[][MAX_FOOD_TYPE_NAME],int typeChoice,int nrDrinks,char drinks[][MAX_DR_CUT_NAME],
                   int pricesDrinks[]);
void displayCutlery(char cutlery[][MAX_DR_CUT_NAME]);
void displayAddInfo(char addinfo[],int *state);

#endif //FOOD_ORDERING_DISPLAY_H
