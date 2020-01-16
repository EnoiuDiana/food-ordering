//
// Created by edian on 05.11.2019.
//
#include <stdio.h>
#include "display.h"
#include <string.h>
#include "userdata.h"
#include "specFoods.h"
#include "drinks.h"
void displayCutlery(char cutlery[][MAX_CUTLERY_NAME]){
    //cutlery
    printf("Do you want cutlery?\n");
    for(int i=0; i<2; i++){
        putchar('a'+i);
        printf(") %s\n",cutlery[i]);
    }
    printf("c) Go back.\n");
}
void displayAddInfo(char addInfo[],int *state){
    //add info
    printf("Any additional info?\n");
    gets(addInfo);
    (*state)++;
}
void displayOrder(specFood *s,drink * d,char cutlery[],char addinfo[],userdata *u){
    //order print
    printf("This is your order:\n"
           "-------------------\n");
    printf("Name: %s\n",u->username);
    printf("Food Items:\n---%s: %.2lf\n---%s: %.2lf\n",s->name,
           s->price,d->name,d->price);
    printf("Cutlery: %s\n",cutlery);
    if(strcmp(addinfo,"\0") != 0){
        printf("Additional info: %s\n",addinfo);
    }
    printf("Payment amount: %.2lf\n",s->price+d->price);
    printf("-------------------\n"
           "a) Confirm order\n"
           "b) Go back\n");
}

