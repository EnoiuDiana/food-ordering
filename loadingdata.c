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

void readFood(char *** foodTypesAddr,int *nrOfFoodTypesAddr,int ** nrSpecTypeAddr,char **** specFoodsAddr,double ***priceFoodsAddr,
              FILE * data){
    int nrOfFoodTypes;
    char line[MAX_LINE];
    fgets(line,MAX_LINE,data);
    sscanf(line,"%d",&nrOfFoodTypes);
    int *nrSpecType = (int *) malloc(nrOfFoodTypes * sizeof(int));
    char **foodTypes = (char **) malloc(nrOfFoodTypes * sizeof(char *));
    char ***specFoods = (char ***) malloc(nrOfFoodTypes * sizeof(char **));
    double **priceFoods = (double **) malloc(nrOfFoodTypes * sizeof(double *));
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
    *nrOfFoodTypesAddr = nrOfFoodTypes;
    *foodTypesAddr = foodTypes;
    *nrSpecTypeAddr = nrSpecType;
    *specFoodsAddr = specFoods;
    *priceFoodsAddr = priceFoods;
}
void readDrinks(int *nrDrinksAddr,char ***drinksAddr,double **pricesDrinksAddr,FILE * data){
    int nrDrinks;
    char line[MAX_LINE];
    fgets(line,MAX_LINE,data);
    sscanf(line,"%d",&nrDrinks);
    char **drinks = (char **) malloc(nrDrinks * sizeof(char *));
    double *pricesDrinks = (double *) malloc(nrDrinks * sizeof(double));
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
    *nrDrinksAddr = nrDrinks;
    *drinksAddr = drinks;
    *pricesDrinksAddr = pricesDrinks;
}
void freeData(int nrOfFoodTypes,int *nrSpecType,char ***specFoods,char **foodTypes,double **priceFoods,int nrDrinks,
        char **drinks,double *pricesDrinks){
    for(int i=0;i<nrOfFoodTypes;i++){
        for(int j=0;j<nrSpecType[i];j++){
            free(specFoods[i][j]);
        }
        free(specFoods[i]);
        free(foodTypes[i]);
        free(priceFoods[i]);
    }
    free(specFoods);
    free(foodTypes);
    free(priceFoods);
    free(nrSpecType);
    for (int i = 0; i<nrDrinks; i++){
        free(drinks[i]);
    }
    free(drinks);
    free(pricesDrinks);
}