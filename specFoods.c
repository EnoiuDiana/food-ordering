//
// Created by edian on 17.12.2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "specFoods.h"
#define MAX_SPEC_TYPE_NAME 300

void readSpecFoods(int noOfSpecTypes,specFood ** specFoodAddr,char *pt){
    specFood * specFoods = (specFood*)malloc(noOfSpecTypes*sizeof(specFood));
    for(int i=0; i < noOfSpecTypes; i++) {
        specFoods[i].name = (char *) malloc(MAX_SPEC_TYPE_NAME * sizeof(char));
        pt = strtok(NULL, "-");
        strcpy(specFoods[i].name, pt);
        strcpy(specFoods[i].name,specFoods[i].name + 2);
        pt = strtok(NULL, ")");
        sscanf(pt, "%lf", &(specFoods[i].price));
    }
    *specFoodAddr = specFoods;
}
void displaySpecificFoods(int noOfSpecTypes, char * foodType, specFood * specFoods){
    //selecting specific food
    printf("Please choose the type of %s:\n",foodType);
    for(int i=0; i < noOfSpecTypes; i++){
        putchar('a'+i);
        printf(") %s: %.2lf\n", specFoods[i].name, specFoods[i].price);
    }
    printf("%c) Go back.\n", 'a' + noOfSpecTypes);
}
void freeSpecFoods(specFood ** s){
    free((**s).name);
}
