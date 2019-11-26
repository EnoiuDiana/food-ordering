//
// Created by edian on 05.11.2019.
//
#include <stdio.h>
#include "display.h"
#include <string.h>

void displayFoodTypes(int nrOfFoodTypes,char ** foodTypes){
    //selecting food type
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0; i<nrOfFoodTypes; i++) {
        putchar('a' + i);
        printf(") %s\n", foodTypes[i]);
    }
    printf("%c) Go back.\n",'a'+nrOfFoodTypes);
}
void displaySpecificFoods(int nrSpecType,char * foodType,char ** specTypes,double * prices){
    //selecting specific food
    printf("Please choose the type of %s:\n",foodType);
    for(int i=0; i<=nrSpecType; i++){
        putchar('a'+i);
        printf(") %s: %.2lf\n",specTypes[i],prices[i]);
    }
    printf("%c) Go back.\n",'a'+nrSpecType+1);
}
void displayDrinks(char * foodType,int nrDrinks,char ** drinks,
                   double * pricesDrinks){
    //selecting drink
    printf("Please choose a drink to go with your %s:\n",foodType);
    for(int i=0; i<nrDrinks; i++){
        putchar('a'+i);
        printf(") %s: %.2lf\n",drinks[i],pricesDrinks[i]);
    }
    printf("%c) Go back.\n",'a'+nrDrinks);
}
void displayCutlery(char cutlery[][MAX_CUTLERY_NAME]){
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
void displayOrder(char * specType,double price,char * drink,double priceDrink,
                  char cutlery[],char addinfo[],char username[]){
    //order print
    printf("This is your order:\n"
           "-------------------\n");
    printf("Name:%s\n",username);
    printf("Food Items:\n---%s: %.2lf\n---%s: %.2lf\n",specType,
           price,drink,priceDrink);
    printf("Cutlery: %s\n",cutlery);
    if(strcmp(addinfo,"\0") != 0){
        printf("Additional info: %s\n",addinfo);
    }
    printf("Payment amount: %.2lf\n",price+priceDrink);
    printf("-------------------\n"
           "a) Confirm order\n"
           "b) Go back\n");
}

