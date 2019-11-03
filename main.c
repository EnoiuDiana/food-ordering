#include <stdio.h>
#include <string.h>
#define MAX_FOOD_TYPE_NAME 10
void inputUserData(char username[],char password[]);
void displayFoodTypes(int nrOfFoodTypes,char foodTypes[][MAX_FOOD_TYPE_NAME]);
int getChoiceIndex(int nrOfChoices,int *state);

int main() {
    printf("Welcome to Food Thingies!\n"
           "Please sign in to continue!\n");

    // food data
    int nrOfFoodTypes = 3;
    char foodTypes[][MAX_FOOD_TYPE_NAME] = {"Pizza","Pasta","Salad"};
    char nrSpecType[] = {3,2,4};
    char specTypes[3][4][100] = {
            {"Pizza Carbonara","Pizza Diavola","Pizza Margherita"},
            {"Chicken alfredo","Mac&cheese"},
            {"Tuna Salad","Chicken Salad","Greek Salad","Cobb"}
    };
    int prices[3][4] = {
            {21,23,19},
            {23,21},
            {23,22,19,21}
    };
    int nrDrinks = 4;
    char drinks[][15] = {"Coca-Cola","Fanta","Lipton","Water"};
    int pricesDrinks[] = {5,5,5,4};
    char cutlery[][15] = {"Yes","No,thanks"};
    char addinfo[100];

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
                //selecting specific food
                printf("Please choose the type of %s:\n",foodTypes[typeChoice]);
                for(int i=0; i<nrSpecType[typeChoice]; i++){
                    putchar('a'+i);
                    printf(") %s: %d\n",specTypes[typeChoice][i],prices[typeChoice][i]);
                }
                printf("%c) Go back.\n",'a'+nrSpecType[typeChoice]);
                choice = getchar();
                //consume new line
                getchar();
                if(choice == 'a'+nrSpecType[typeChoice]){
                    state--;
                    break;
                }
                specTypeChoice = choice - 'a';
                state++;
                break;
            }
            case 3: {
                //selecting drink
                printf("Please choose a drink to go with your %s:\n",foodTypes[typeChoice]);
                for(int i=0; i<nrDrinks; i++){
                    putchar('a'+i);
                    printf(") %s: %d\n",drinks[i],pricesDrinks[i]);
                }
                printf("%c) Go back.\n",'a'+nrDrinks);
                choice = getchar();
                //consume new line
                getchar();
                if(choice == 'a'+nrDrinks){
                    state--;
                    break;
                }
                drinkChoice = choice - 'a';
                state++;
                break;
            }
            case 4: {
                //cutlery
                printf("Do you want cutlery?\n");
                for(int i=0; i<2; i++){
                    putchar('a'+i);
                    printf(") %s\n",cutlery[i]);
                }
                printf("c) Go back.\n");
                choice = getchar();
                //consume new line
                getchar();
                if(choice == 'c'){
                    state--;
                    break;
                }
                cutleryChoice = choice - 'a';
                state++;
                break;
            }
            case 5: {
                //add info
                printf("Any additional info?\n");
                gets(addinfo);
                printf("%s",addinfo);
                state++;
                break;
            }
            case 6: {
                //order print
                printf("This is your order:\n"
                       "-------------------\n");
                printf("Name:%s\n",username);
                printf("Food Items:\n---%s: %d\n---%s: %d\n",specTypes[typeChoice][specTypeChoice],
                       prices[typeChoice][specTypeChoice],drinks[drinkChoice],pricesDrinks[drinkChoice]);
                printf("Cutlery: %s\n",cutlery[cutleryChoice]);
                if(strcmp(addinfo,"\0") != 0){
                    printf("Additional info: %s\n",addinfo);
                }
                printf("Payment amount: %d\n",prices[typeChoice][specTypeChoice]+pricesDrinks[drinkChoice]);
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