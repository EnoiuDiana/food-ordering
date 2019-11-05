//
// Created by edian on 05.11.2019.
//
#include <stdio.h>

void inputUserData(char username[],char password[]){
    //user input
    printf("---Username\n");
    gets(username);
    printf("---Password\n");
    gets(password);
}
void displayUserData(char username[]){
    printf("Name:%s\n",username);
}
