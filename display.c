//
// Created by edian on 05.11.2019.
//
#include <stdio.h>
#include "display.h"
#include <string.h>

void displayFoodTypes(int nrOfFoodTypes,char foodTypes[][MAX_FOOD_TYPE_NAME]){
    //selecting food type
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0; i<nrOfFoodTypes; i++) {
        putchar('a' + i);
        printf(") %s\n", foodTypes[i]);
    }
    printf("%c) Go back.\n",'a'+nrOfFoodTypes);
}
void displaySpecificFoods(int nrSpecType[],int typeChoice,char foodTypes[][MAX_FOOD_TYPE_NAME],
                          char specTypes[][MAX_NR_SPEC_TYPES][MAX_SPEC_TYPE_NAME],int prices[][MAX_NR_PRICES]){
    //selecting specific food
    printf("Please choose the type of %s:\n",foodTypes[typeChoice]);
    for(int i=0; i<nrSpecType[typeChoice]; i++){
        putchar('a'+i);
        printf(") %s: %d\n",specTypes[typeChoice][i],prices[typeChoice][i]);
    }
    printf("%c) Go back.\n",'a'+nrSpecType[typeChoice]);
}
void displayDrinks(char foodTypes[][MAX_FOOD_TYPE_NAME],int typeChoice,int nrDrinks,char drinks[][MAX_DR_CUT_NAME],
                   int pricesDrinks[]){
    //selecting drink
    printf("Please choose a drink to go with your %s:\n",foodTypes[typeChoice]);
    for(int i=0; i<nrDrinks; i++){
        putchar('a'+i);
        printf(") %s: %d\n",drinks[i],pricesDrinks[i]);
    }
    printf("%c) Go back.\n",'a'+nrDrinks);
}
void displayCutlery(char cutlery[][MAX_DR_CUT_NAME]){
    //cutlery
    printf("Do you want cutlery?\n");
    for(int i=0; i<2; i++){
        putchar('a'+i);
        printf(") %s\n",cutlery[i]);
    }
    printf("c) Go back.\n");
}
void displayAddInfo(char addInfo[],int *state){
    //add info
    printf("Any additional info?\n");
    gets(addInfo);
    (*state)++;
}
void displayOrder(char specTypes[][MAX_NR_SPEC_TYPES][MAX_SPEC_TYPE_NAME],int typeChoice,int specTypeChoice,
                  int prices[][MAX_NR_PRICES],char drinks[][MAX_DR_CUT_NAME],int drinkChoice,int pricesDrinks[],
                  char cutlery[][MAX_DR_CUT_NAME],int cutleryChoice,char addinfo[],char username[]){
    //order print
    printf("This is your order:\n"
           "-------------------\n");
    printf("Name:%s\n",username);
    printf("Food Items:\n---%s: %d\n---%s: %d\n",specTypes[typeChoice][specTypeChoice],
           prices[typeChoice][specTypeChoice],drinks[drinkChoice],pricesDrinks[drinkChoice]);
    printf("Cutlery: %s\n",cutlery[cutleryChoice]);
    if(strcmp(addinfo,"\0") != 0){
        printf("Additional info: %s\n",addinfo);
    }
    printf("Payment amount: %d\n",prices[typeChoice][specTypeChoice]+pricesDrinks[drinkChoice]);
    printf("-------------------\n"
           "a) Confirm order\n"
           "b) Go back\n");
}

