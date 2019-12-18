//
// Created by edian on 05.11.2019.
//

#ifndef FOOD_ORDERING_USERDATA_H
#define FOOD_ORDERING_USERDATA_H
#define TABULA_RECTA_NO_ROWS_COLUMNS 200
typedef struct _userdata{
    char *username;
    char *password;
}userdata;
userdata createUser();
void inputUserData(userdata * u);
int validateUsernameSignIn(char username[],char existingUsername[]);
int validatePasswordSignIn(char password[],char existingPassword[]);
int validateUsernameSignUp(char username[],char existingUsername[]);
void signingIn(char username[],char password[],int * sign_in,int *state,int tabulaRecta[][TABULA_RECTA_NO_ROWS_COLUMNS],FILE*readAccounts);
void signingUp(char username[],char password[],int * sign_up,int tabulaRecta[][TABULA_RECTA_NO_ROWS_COLUMNS],FILE * createNewAccount);
int validatePasswordSignUp(int (*fullfillscondition)(char[]),char password[],char error[]);
void generateEncryptionDecryptionKey(int tabulaRecta[][TABULA_RECTA_NO_ROWS_COLUMNS]);
void encryptPassword(char password[],int tabulaRecta[][TABULA_RECTA_NO_ROWS_COLUMNS]);
void decryptPassword(char password[],int tabulaRecta[][TABULA_RECTA_NO_ROWS_COLUMNS]);
#endif //FOOD_ORDERING_USERDATA_H
