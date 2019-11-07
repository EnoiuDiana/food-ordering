#include <stdio.h>
#include "userdata.h"
#include "display.h"
#include "choice.h"

int main() {
    printf("Welcome to Food Thingies!\nPlease sign in to continue!\n");
    // food data
    int nrOfFoodTypes = 3,nrSpecType[] = {3,2,4},nrDrinks = 4, pricesDrinks[] = {5,5,5,4}, prices[3][MAX_NR_PRICES] = {
            {21,23,19},
            {23,21},
            {23,22,19,21}
    };
    char foodTypes[][MAX_FOOD_TYPE_NAME] = {"Pizza","Pasta","Salad"}, specTypes[3][MAX_NR_SPEC_TYPES][MAX_SPEC_TYPE_NAME] = {
            {"Pizza Carbonara","Pizza Diavola","Pizza Margherita"},
            {"Chicken alfredo","Mac&cheese"},
            {"Tuna Salad","Chicken Salad","Greek Salad","Cobb"}
    };
    char drinks[][MAX_DR_CUT_NAME] = {"Coca-Cola","Fanta","Lipton","Water"},cutlery[][MAX_DR_CUT_NAME] = {"Yes","No,thanks"}, addInfo[200];
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
                displaySpecificFoods(nrSpecType[typeChoice],foodTypes[typeChoice],specTypes[typeChoice],prices[typeChoice]);
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
                displayOrder(specTypes[typeChoice][specTypeChoice],prices[typeChoice][specTypeChoice],
                        drinks[drinkChoice],pricesDrinks[drinkChoice],cutlery[cutleryChoice],addInfo,username);
                confirmChoice = getChoiceIndex(1, &state);
                confirmOrder(confirmChoice, &order, &state);
                break;
            }
        }
    }
    printf("Order confirmed! Thank you for buying from us, %s!\n",username);
    return 0;
}
