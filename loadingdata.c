//
// Created by edian on 07.12.2019.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STRING 300
#define MAX_LINE 10
#define MAX_FOOD_TYPE_NAME 100
#define MAX_SPEC_TYPE_NAME 300
#define MAX_DRINK_NAME 50

void readNoOf(int *noOf, FILE * data){
    char line[MAX_LINE];
    fgets(line,MAX_LINE,data);
    sscanf(line,"%d",&(*noOf));
}
void readFood(char ** foodTypes,int nrOfFoodTypes,int * nrSpecType,char *** specFoods,double **priceFoods,
              FILE * data){
    char * pt, string[MAX_STRING];
    for (int i = 0; i < nrOfFoodTypes; i++) {
        foodTypes[i] = (char *) malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
        fgets(string,MAX_STRING,data);
        pt = strtok(string, " ");
        strcpy(foodTypes[i], pt);
        pt = strtok(NULL, ":");
        sscanf(pt,"%d",&nrSpecType[i]);
        specFoods[i] = (char **) malloc(nrSpecType[i] * sizeof(char *));
        priceFoods[i] = (double *) malloc(nrSpecType[i] * sizeof(double));
        for(int j=0;j<nrSpecType[i];j++) {
            specFoods[i][j] = (char *) malloc(MAX_SPEC_TYPE_NAME * sizeof(char));
            pt = strtok(NULL, "-");
            strcpy(specFoods[i][j], pt);
            strcpy(specFoods[i][j],specFoods[i][j]+2);
            pt = strtok(NULL, ")");
            sscanf(pt, "%lf", &(priceFoods[i][j]));
        }
    }
}
void readDrinks(int nrDrinks,char **drinks,double *pricesDrinks,FILE * data){
    char * pt, string[MAX_STRING];
    fgets(string,MAX_STRING,data);
    strrev(string); // reversed the string so that if drinks name contain '-' it won't affect the program
    pt = strtok(string, "-");
    for (int i = nrDrinks-1; i >= 0; i--) {
        drinks[i] = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
        if (i != nrDrinks-1)pt = strtok(NULL, "-");
        sscanf(strrev(pt), "%lf", &pricesDrinks[i]);
        pt = strtok(NULL, "(");
        strcpy(drinks[i], pt);
        strrev(drinks[i]);
    }
}