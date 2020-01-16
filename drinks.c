//
// Created by edian on 17.12.2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "drinks.h"
#define MAX_DRINK_NAME 50
#define MAX_STRING 300
#define MAX_LINE 10
void readDrinks(int *nrDrinksAddr,drink ** drinkAddr,FILE * data){
    int nrDrinks;
    char line[MAX_LINE];
    fgets(line,MAX_LINE,data);
    sscanf(line,"%d",&nrDrinks);
    drink * drinks = (drink*)malloc(nrDrinks*sizeof(drink));
    char * pt, string[MAX_STRING];
    fgets(string,MAX_STRING,data);
    strrev(string); // reversed the string so that if drinks name contain '-' it won't affect the program
    pt = strtok(string, "-");
    for (int i = nrDrinks-1; i >= 0; i--) {
        drinks[i].name = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
        if (i != nrDrinks-1)pt = strtok(NULL, "-");
        sscanf(strrev(pt), "%lf", &drinks[i].price);
        pt = strtok(NULL, "(");
        strcpy(drinks[i].name, pt);
        strrev(drinks[i].name);
    }
    *nrDrinksAddr = nrDrinks;
    *drinkAddr = drinks;
}
void displayDrinks(char * foodType,int nrDrinks, drink * d){
    //selecting drink
    printf("Please choose a drink to go with your %s:\n",foodType);
    for(int i=0; i<nrDrinks; i++){
        putchar('a'+i);
        printf(") %s: %.2lf\n",d[i].name,d[i].price);
    }
    printf("%c) Go back.\n",'a'+nrDrinks);
}
void freeDrinks(int nrDrinks,drink * d){
    for (int i = 0; i<nrDrinks; i++){
        free(d[i].name);
    }
    free(d);
}