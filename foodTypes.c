//
// Created by edian on 07.12.2019.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "specFoods.h"
#include "foodTypes.h"
#define MAX_STRING 300
#define MAX_LINE 10
#define MAX_FOOD_TYPE_NAME 100
#define MAX_SPEC_TYPE_NAME 300
#define MAX_DRINK_NAME 50
void readFoodTypes(char **foodTypeAddr,int *noOfSpecTypesAddr,char *pt){
    char *foodType = (char *) malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
    strcpy(foodType, pt);
    pt = strtok(NULL, ":");
    int noOfSpecTypes;
    sscanf(pt,"%d",&noOfSpecTypes);
    *foodTypeAddr = foodType;
    *noOfSpecTypesAddr = noOfSpecTypes;
}
void readFood(foodType**foodTypeAddr, int *nrOfFoodTypesAddr, FILE * data){
    int nrOfFoodTypes;
    char line[MAX_LINE];
    fgets(line,MAX_LINE,data);
    sscanf(line,"%d",&nrOfFoodTypes);
    foodType * foodTypes = (foodType*)malloc(nrOfFoodTypes*sizeof(foodType));
    //specFood ** specFoods = (specFood**)malloc(nrOfFoodTypes*sizeof(specFood*));
    char * pt, string[MAX_STRING];
    for (int i = 0; i < nrOfFoodTypes; i++) {
        //read the whole line
        fgets(string,MAX_STRING,data);
        pt = strtok(string, " ");
        //read food types
        readFoodTypes(&foodTypes[i].name,&foodTypes[i].noOfSpecType,pt);
        //read spec food
        readSpecFoods(foodTypes[i].noOfSpecType,&(foodTypes[i].specType),pt);
    }
    *nrOfFoodTypesAddr = nrOfFoodTypes;
    *foodTypeAddr = foodTypes;
}
void displayFoodTypes(int nrOfFoodTypes,foodType * foodTypes){
    //selecting food type
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0; i<nrOfFoodTypes; i++) {
        putchar('a' + i);
        printf(") %s\n", foodTypes[i].name);
    }
    printf("%c) Go back.\n",'a'+nrOfFoodTypes);
}
void freeFoodType(int nrOfFoodTypes,foodType * foodTypes){
    for(int i=0;i<nrOfFoodTypes;i++){
        for(int j=0;j<foodTypes[i].noOfSpecType;j++){
            free(&(foodTypes[i].specType[j]));
        }
        free(foodTypes[i].specType);
        free(foodTypes[i].name);
    }
    free(foodTypes);
}