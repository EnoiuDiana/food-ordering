#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "userdata.h"
#include "display.h"
#include "choice.h"

int main() {
    char string[300],line[10];
    char *pt;
    int nrOfFoodTypes,nrDrinks,nrSpecType[MAX_NR_SPEC_TYPES],k;
    printf("PLease load the data:\n");
    //loading food data
    gets(line);
    sscanf(line,"%d",&nrOfFoodTypes);
    char ** foodTypes = (char**)malloc(nrOfFoodTypes * sizeof(char*));
    char *** specFoods = (char***)malloc(nrOfFoodTypes * sizeof(char**));
    double ** priceFoods = (double**)malloc(nrOfFoodTypes * sizeof(double*));
    for(int i=0;i<nrOfFoodTypes;i++) {
        foodTypes[i] = (char*)malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
        specFoods[i] = (char**)malloc(MAX_NR_SPEC_TYPES * sizeof(char*));
        priceFoods[i] = (double*)malloc(MAX_NR_SPEC_TYPES * sizeof(double));
        gets(string);
        pt = strtok(string, ":");
        strcpy(foodTypes[i],pt);
        pt = strtok(NULL, "(");
        k = 0;//k counts the number of spec foods
        while (pt != NULL) {
            pt = strtok(NULL, "-");
            specFoods[i][k] = (char*)malloc(MAX_SPEC_TYPE_NAME * sizeof(char));
            strcpy(specFoods[i][k],pt);
            specFoods[i][k][strlen(pt)-1]='\0';
            pt = strtok(NULL, ")");
            sscanf(pt, "%lf", &priceFoods[i][k]);
            pt = strtok(NULL, "(");
            k++;
        }
        nrSpecType[i]=k;
    }
    //loading drinks data
    gets(line);
    sscanf(line,"%d",&nrDrinks);
    char ** drinks = (char**)malloc(nrDrinks * sizeof(char*));
    double * pricesDrinks = (double*)malloc(nrDrinks * sizeof(double));
    gets(string);
    strrev(string); // reversed the string so that if drinks name contain '-' it won't affect the program
    pt = strtok(string,"-");
    for(int i=0;i<nrDrinks;i++){
        if(i!=0)pt = strtok(NULL,"-");
        sscanf(strrev(pt),"%lf",&pricesDrinks[i]);
        drinks[i] = (char*)malloc(MAX_DRINK_NAME * sizeof(char));
        pt = strtok(NULL,"(");
        strcpy(drinks[i],pt);
        strrev(drinks[i]);
    }
    //load data for cutlery and addinfo
    char cutlery[][MAX_CUTLERY_NAME] = {"Yes","No,thanks"}, addInfo[200];
    printf("Welcome to Food Thingies!\nPlease sign in to continue!\n");
    //user input
    char username[20], password[20];
    int typeChoice, specTypeChoice, drinkChoice, cutleryChoice, confirmChoice;

    int state=0, order=0;
    while(!order) {
        switch(state) {
            case 0: {
                inputUserData(username,password);
                state++;
                break;
            }
            case 1: {
                displayFoodTypes(nrOfFoodTypes,foodTypes);
                typeChoice = getChoiceIndex(nrOfFoodTypes, &state);
                break;
            }
            case 2: {
                displaySpecificFoods(nrSpecType[typeChoice], foodTypes[typeChoice], specFoods[typeChoice], priceFoods[typeChoice]);
                specTypeChoice = getChoiceIndex(nrSpecType[typeChoice], &state);
                break;
            }
            case 3: {
                displayDrinks(foodTypes[typeChoice],nrDrinks,drinks,pricesDrinks);
                drinkChoice = getChoiceIndex(nrDrinks, &state);
                break;
            }
            case 4: {
                displayCutlery(cutlery);
                cutleryChoice = getChoiceIndex(2, &state);
                break;
            }
            case 5: {
                displayAddInfo(addInfo,&state);
                break;
            }
            case 6: {
                displayOrder(specFoods[typeChoice][specTypeChoice], priceFoods[typeChoice][specTypeChoice],
                             drinks[drinkChoice], pricesDrinks[drinkChoice], cutlery[cutleryChoice], addInfo, username);
                confirmChoice = getChoiceIndex(1, &state);
                confirmOrder(confirmChoice, &order, &state);
                break;
            }
        }
    }
    printf("Order confirmed! Thank you for buying from us, %s!\n",username);
    for(int i=0;i<nrOfFoodTypes;i++){
        for(int j=0;j<=nrSpecType[i];j++){
            free(specFoods[i][j]);
        }
        free(specFoods[i]);
        free(foodTypes[i]);
        free(priceFoods[i]);
    }
    free(specFoods);
    free(foodTypes);
    free(priceFoods);
    for(int i=0;i<nrDrinks;i++){
        free(drinks[i]);
    }
    free(drinks);
    free(pricesDrinks);
    return 0;
}
