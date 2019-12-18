#include <stdio.h>
#include <stdlib.h>
#include "userdata.h"
#include "display.h"
#include "choice.h"
#include "foodTypes.h"
#include "drinks.h"
#include "specFoods.h"
void freeData(foodType* foodTypes,int nrOfFoodTypes, int nrDrinks,drink  * d);
int main() {
    //open file data.txt
    FILE *data;
    data = fopen("C:\\Users\\edian\\Desktop\\Faculta\\an1\\cp lab\\food-data-provider\\data.txt","r");
    //initialization
    int nrOfFoodTypes,nrDrinks,*noOfSpecTypes;
    if(data == NULL){
        data = stdin;
        printf("PLease load the data:\n");
    }
    //loading food data
    foodType * foodTypes;
    readFood(&foodTypes, &nrOfFoodTypes, data);
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
                displayFoodTypes(nrOfFoodTypes, foodTypes);
                typeChoice = getChoiceIndex(nrOfFoodTypes, &state);
                break;
            }
            case 2: {
                displaySpecificFoods(foodTypes[typeChoice].noOfSpecType, foodTypes[typeChoice].name,foodTypes[typeChoice].specType);
                specTypeChoice = getChoiceIndex(foodTypes[typeChoice].noOfSpecType, &state);
                break;
            }
            case 3: {
                displayDrinks(foodTypes[typeChoice].name, nrDrinks, drinks);
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
                displayOrder(&(foodTypes[typeChoice].specType[specTypeChoice]),
                             &drinks[drinkChoice], cutlery[cutleryChoice], addInfo, &u);
                confirmChoice = getChoiceIndex(1, &state);
                confirmOrder(confirmChoice, &order, &state);
                break;
            }
        }
    }
    printf("Order confirmed! Thank you for buying from us, %s!\n",u.username);
    //free memory
    freeData(foodTypes,nrOfFoodTypes, nrDrinks, drinks);
    return 0;
}
void freeData(foodType* foodTypes,int nrOfFoodTypes, int nrDrinks,drink  * d){
    freeSpecFoods(foodTypes->specType);
    freeFoodType(nrOfFoodTypes,foodTypes);
    freeDrinks(nrDrinks,d);
}
