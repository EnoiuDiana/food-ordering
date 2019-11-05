//
// Created by edian on 05.11.2019.
//
#include <stdio.h>

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
void confirmOrder(int confirmChoice,int *order,int *state){
    if(confirmChoice == 0){
        (*order) = 1;
    } else {
        (*state)--;
    }
}
