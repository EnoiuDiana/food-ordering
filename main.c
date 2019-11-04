#include <stdio.h>
#include <string.h>
#define MAX_FOOD_TYPE_NAME 10
#define MAX_SPEC_TYPE_NAME 100
#define MAX_NR_SPEC_TYPES 4
#define MAX_NR_PRICES 4
#define MAX_DR_CUT_NAME 15

void inputUserData(char username[],char password[]);
void displayFoodTypes(int nrOfFoodTypes,char foodTypes[][MAX_FOOD_TYPE_NAME]);
int getChoiceIndex(int nrOfChoices,int *state);
void displaySpecificFoods(int nrSpecType[],int typeChoice,char foodTypes[][MAX_FOOD_TYPE_NAME],
        char specTypes[][MAX_NR_SPEC_TYPES][MAX_SPEC_TYPE_NAME],int prices[][MAX_NR_PRICES]);
void displayDrinks(char foodTypes[][MAX_FOOD_TYPE_NAME],int typeChoice,int nrDrinks,char drinks[][MAX_DR_CUT_NAME],
        int pricesDrinks[]);
void displayCutlery(char cutlery[][MAX_DR_CUT_NAME]);
void displayOrder(char specTypes[][MAX_NR_SPEC_TYPES][MAX_SPEC_TYPE_NAME],int typeChoice,int specTypeChoice,
        int prices[][MAX_NR_PRICES],char drinks[][MAX_DR_CUT_NAME],int drinkChoice,int pricesDrinks[],
        char cutlery[][MAX_DR_CUT_NAME],int cutleryChoice,char addinfo[]);

int main() {
    printf("Welcome to Food Thingies!\n"
           "Please sign in to continue!\n");

    // food data
    int nrOfFoodTypes = 3;
    char foodTypes[][MAX_FOOD_TYPE_NAME] = {"Pizza","Pasta","Salad"};
    int nrSpecType[] = {3,2,4};
    char specTypes[3][MAX_NR_SPEC_TYPES][MAX_SPEC_TYPE_NAME] = {
            {"Pizza Carbonara","Pizza Diavola","Pizza Margherita"},
            {"Chicken alfredo","Mac&cheese"},
            {"Tuna Salad","Chicken Salad","Greek Salad","Cobb"}
    };
    int prices[3][MAX_NR_PRICES] = {
            {21,23,19},
            {23,21},
            {23,22,19,21}
    };
    int nrDrinks = 4;
    char drinks[][MAX_DR_CUT_NAME] = {"Coca-Cola","Fanta","Lipton","Water"};
    int pricesDrinks[] = {5,5,5,4};
    char cutlery[][MAX_DR_CUT_NAME] = {"Yes","No,thanks"};
    char addinfo[200];

    //user input
    char username[20];
    char password[20];
    int choice, typeChoice, specTypeChoice, drinkChoice, cutleryChoice;

    //code
    int state=0;
    int order=0;
    while(!order) {
        switch(state) {
            case 0: {
                //user input
                inputUserData(username,password);
                state++;
                break;
            }
            case 1: {
                //selecting food type
                displayFoodTypes(nrOfFoodTypes,foodTypes);
                typeChoice = getChoiceIndex(nrOfFoodTypes, &state);
                break;
            }
            case 2: {
                //selecting specific food
                displaySpecificFoods(nrSpecType,typeChoice,foodTypes,specTypes,prices);
                specTypeChoice = getChoiceIndex(nrSpecType[typeChoice], &state);
                break;
            }
            case 3: {
                //selecting drink
                displayDrinks(foodTypes,typeChoice,nrDrinks,drinks,pricesDrinks);
                drinkChoice = getChoiceIndex(nrDrinks, &state);
                break;
            }
            case 4: {
                //cutlery
                displayCutlery(cutlery);
                cutleryChoice = getChoiceIndex(2, &state);
                break;
            }
            case 5: {
                //add info
                printf("Any additional info?\n");
                gets(addinfo);
                state++;
                break;
            }
            case 6: {
                //order print
                printf("This is your order:\n"
                       "-------------------\n");
                printf("Name:%s\n",username);
                displayOrder(specTypes,typeChoice,specTypeChoice,prices,drinks,drinkChoice,pricesDrinks,cutlery,
                cutleryChoice,addinfo);
                printf("-------------------\n"
                       "a) Confirm order\n"
                       "b) Go back\n");
                choice = getchar();
                //consume new line
                getchar();
                if(choice == 'b'){
                    state--;
                    state--;
                    break;
                }
                else {
                    order=1;
                }
                state++;
                break;
            }
        }
    }
    printf("Order confirmed! Thank you for buying from us, %s!\n",username);
    return 0;
}
void inputUserData(char username[],char password[]){
    //user input
    printf("---Username\n");
    gets(username);
    printf("---Password\n");
    gets(password);
}
void displayFoodTypes(int nrOfFoodTypes,char foodTypes[][MAX_FOOD_TYPE_NAME]){
    //selecting food type
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0; i<nrOfFoodTypes; i++) {
        putchar('a' + i);
        printf(") %s\n", foodTypes[i]);
    }
    printf("%c) Go back.\n",'a'+nrOfFoodTypes);
}
int getChoiceIndex(int nrOfChoices,int *state){
    int choiceIndex;
    char choice = getchar();
    //consume new line
    getchar();
    if(choice == 'a'+nrOfChoices){
        (*state)--;
    } else {
        choiceIndex = choice - 'a';
        (*state)++;
    }
    return choiceIndex;
}
void displaySpecificFoods(int nrSpecType[],int typeChoice,char foodTypes[][MAX_FOOD_TYPE_NAME],
        char specTypes[][MAX_NR_SPEC_TYPES][MAX_SPEC_TYPE_NAME],int prices[][MAX_NR_PRICES]){
    //selecting specific food
    printf("Please choose the type of %s:\n",foodTypes[typeChoice]);
    for(int i=0; i<nrSpecType[typeChoice]; i++){
        putchar('a'+i);
        printf(") %s: %d\n",specTypes[typeChoice][i],prices[typeChoice][i]);
    }
    printf("%c) Go back.\n",'a'+nrSpecType[typeChoice]);
}
void displayDrinks(char foodTypes[][MAX_FOOD_TYPE_NAME],int typeChoice,int nrDrinks,char drinks[][MAX_DR_CUT_NAME],
        int pricesDrinks[]){
    //selecting drink
    printf("Please choose a drink to go with your %s:\n",foodTypes[typeChoice]);
    for(int i=0; i<nrDrinks; i++){
        putchar('a'+i);
        printf(") %s: %d\n",drinks[i],pricesDrinks[i]);
    }
    printf("%c) Go back.\n",'a'+nrDrinks);
}
void displayCutlery(char cutlery[][MAX_DR_CUT_NAME]){
    printf("Do you want cutlery?\n");
    for(int i=0; i<2; i++){
        putchar('a'+i);
        printf(") %s\n",cutlery[i]);
    }
    printf("c) Go back.\n");
}
void displayOrder(char specTypes[][MAX_NR_SPEC_TYPES][MAX_SPEC_TYPE_NAME],int typeChoice,int specTypeChoice,
        int prices[][MAX_NR_PRICES],char drinks[][MAX_DR_CUT_NAME],int drinkChoice,int pricesDrinks[],
        char cutlery[][MAX_DR_CUT_NAME],int cutleryChoice,char addinfo[]){
    printf("Food Items:\n---%s: %d\n---%s: %d\n",specTypes[typeChoice][specTypeChoice],
           prices[typeChoice][specTypeChoice],drinks[drinkChoice],pricesDrinks[drinkChoice]);
    printf("Cutlery: %s\n",cutlery[cutleryChoice]);
    if(strcmp(addinfo,"\0") != 0){
        printf("Additional info: %s\n",addinfo);
    }
    printf("Payment amount: %d\n",prices[typeChoice][specTypeChoice]+pricesDrinks[drinkChoice]);
}