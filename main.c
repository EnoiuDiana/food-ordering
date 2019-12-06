#include <stdio.h>
#include <stdlib.h>
#include "userdata.h"
#include "display.h"
#include "choice.h"
#include "loadingdata.h"

int main() {
    //open file data.txt
    FILE *data;
    data = fopen("C:\\Users\\edian\\Desktop\\Faculta\\an1\\cp lab\\food-data-provider\\data.txt","r");
    int nrOfFoodTypes, nrDrinks, *nrSpecType;
    char **foodTypes, ***specFoods, **drinks;
    double **priceFoods, *pricesDrinks;
    if(data == NULL){
        data = stdin;
        printf("PLease load the data:\n");
    }
    //loading food data
    readNoOf(&nrOfFoodTypes,data);
    foodTypes = (char **) malloc(nrOfFoodTypes * sizeof(char *));
    specFoods = (char ***) malloc(nrOfFoodTypes * sizeof(char **));
    priceFoods = (double **) malloc(nrOfFoodTypes * sizeof(double *));
    nrSpecType = (int *) malloc(nrOfFoodTypes * sizeof(int));
    readFood(foodTypes,nrOfFoodTypes,nrSpecType,specFoods,priceFoods,data);
    //loading drinks data
    readNoOf(&nrDrinks,data);
    drinks = (char **) malloc(nrDrinks * sizeof(char *));
    pricesDrinks = (double *) malloc(nrDrinks * sizeof(double));
    readDrinks(nrDrinks,drinks,pricesDrinks,data);
    //load data for cutlery and addinfo
    char cutlery[][MAX_CUTLERY_NAME] = {"Yes","No,thanks"}, addInfo[200];
    //user input
    char username[200], password[200];
    int typeChoice=0, specTypeChoice=0, drinkChoice=0, cutleryChoice=0, confirmChoice=0;

    int state=0, order=0;
    while(!order) {
        switch(state) {
            case 0: {
                printf("Welcome to Food Thingies!\n");
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
    //free memory
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
    //close file data.txt
    fclose(data);
    return 0;
}

