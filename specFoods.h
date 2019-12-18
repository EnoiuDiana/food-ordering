//
// Created by edian on 17.12.2019.
//

#ifndef FOOD_ORDERING_SPECFOODS_H
#define FOOD_ORDERING_SPECFOODS_H
typedef struct _specFood{
    char *name;
    double price;
}specFood;
void readSpecFoods(int noOfSpecTypes,specFood ** specFoodAddr,char *pt);
void displaySpecificFoods(int noOfSpecTypes, char * foodType, specFood * specFoods);
void freeSpecFoods(specFood ** s);
#endif //FOOD_ORDERING_SPECFOODS_H
