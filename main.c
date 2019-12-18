#include <stdio.h>
#include <stdlib.h>
#include "userdata.h"
#include "display.h"
#include "choice.h"
#include "foodTypes.h"
#include "drinks.h"
#include "specFoods.h"
void freeData(specFood ** s,int nrOfFoodTypes, char **foodType, int nrDrinks,drink  * d);
int main() {
    //open file data.txt
    FILE *data;
    data = fopen("C:\\Users\\edian\\Desktop\\Faculta\\an1\\cp lab\\food-data-provider\\data.txt","r");
    //initialization
    int nrOfFoodTypes,nrDrinks,*noOfSpecTypes;
    char **foodType;
    if(data == NULL){
        data = stdin;
        printf("PLease load the data:\n");
    }
    //loading food data
    specFood ** specFoodMatrix;
    readFood(&specFoodMatrix,&foodType, &nrOfFoodTypes, &noOfSpecTypes, data);
    //loading drinks data
    drink * drinks;
    readDrinks(&nrDrinks,&drinks,data);
    //close file data.txt
    fclose(data);
    //load data for cutlery and addinfo
    char cutlery[][MAX_CUTLERY_NAME] = {"Yes","No,thanks"}, addInfo[200];
    //user input
    userdata u = createUser();
    int typeChoice=0, specTypeChoice=0, drinkChoice=0, cutleryChoice=0, confirmChoice=0;
    //sign in/up and order food
    int state=0, order=0;
    while(!order) {
        switch(state) {
            case 0: {
                printf("Welcome to Food Thingies!\n");
                inputUserData(&u);
                state++;
                break;
            }
            case 1: {
                displayFoodTypes(nrOfFoodTypes, foodType);
                typeChoice = getChoiceIndex(nrOfFoodTypes, &state);
                break;
            }
            case 2: {
                displaySpecificFoods(noOfSpecTypes[typeChoice], foodType[typeChoice],specFoodMatrix[typeChoice]);
                specTypeChoice = getChoiceIndex(noOfSpecTypes[typeChoice], &state);
                break;
            }
            case 3: {
                displayDrinks(foodType[typeChoice], nrDrinks, drinks);
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
                displayOrder(&specFoodMatrix[typeChoice][specTypeChoice],
                             &drinks[drinkChoice], cutlery[cutleryChoice], addInfo, &u);
                confirmChoice = getChoiceIndex(1, &state);
                confirmOrder(confirmChoice, &order, &state);
                break;
            }
        }
    }
    printf("Order confirmed! Thank you for buying from us, %s!\n",u.username);
    //free memory
    freeData(specFoodMatrix,nrOfFoodTypes, foodType, nrDrinks, drinks);
    return 0;
}
void freeData(specFood ** s,int nrOfFoodTypes, char **foodType, int nrDrinks,drink  * d){
    freeSpecFoods(s);
    freeFoodType(nrOfFoodTypes,foodType);
    freeDrinks(nrDrinks,d);
}
