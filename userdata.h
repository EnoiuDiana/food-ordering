//
// Created by edian on 05.11.2019.
//

#ifndef FOOD_ORDERING_USERDATA_H
#define FOOD_ORDERING_USERDATA_H
void inputUserData(char username[],char password[]);
int validateUsernameSignIn(char username[]);
int validatePasswordSignIn(char password[]);
int validateUsernameSignUp(char username[]);
void signinIn(char username[],char password[],int * sign_in_up,int *state);
void signinUp(char username[],char password[],int * sign_up);
int validatePasswordSignUp(int (*fullfillscondition)(char[]),char password[],char error[]);
#endif //FOOD_ORDERING_USERDATA_H
