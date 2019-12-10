//
// Created by edian on 05.11.2019.
//

#ifndef FOOD_ORDERING_USERDATA_H
#define FOOD_ORDERING_USERDATA_H
#define TABULA_RECTA_NO_ROWS_COLUMNS 200
void inputUserData(char username[],char password[]);
int validateUsernameSignIn(char username[]);
int validatePasswordSignIn(char password[]);
int validateUsernameSignUp(char username[]);
void signingIn(char username[],char password[],int * sign_in_up,int *state);
void signingUp(char username[],char password[],int * sign_up,int tabulaRecta[][TABULA_RECTA_NO_ROWS_COLUMNS],FILE * createNewAccount);
int validatePasswordSignUp(int (*fullfillscondition)(char[]),char password[],char error[]);
void generateEncryptionDecryptionKey(int tabulaRecta[][TABULA_RECTA_NO_ROWS_COLUMNS]);
void encryptPassword(char password[],int tabulaRecta[][TABULA_RECTA_NO_ROWS_COLUMNS]);
#endif //FOOD_ORDERING_USERDATA_H
