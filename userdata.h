//
// Created by edian on 05.11.2019.
//

#ifndef FOOD_ORDERING_USERDATA_H
#define FOOD_ORDERING_USERDATA_H

void inputUserData(char username[],char password[]);
int validateUsernameSignIn(char username[]);
int validatePasswordSignIn(char password[]);
int validateUsernameSignUp(char username[]);
void signinIn(char username[],char password[],int * sign_in_up,int *state,char message[],char message_pass[],char message_user[]);
void signinUp(char username[],char password[],int * sign_up,char message[],char err_user[],char err_length[],
              char err_pass_not_username[],char err_special_char[],char err_digits[]);
int validatePasswordSignUp(int (*fullfillscondition)(char[]),char password[],char error[]);
#endif //FOOD_ORDERING_USERDATA_H
