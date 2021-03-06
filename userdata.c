//
// Created by edian on 05.11.2019.
//
#include <stdio.h>
#include <string.h>
#include "userdata.h"
#include <ctype.h>
#include <stdlib.h>
#define MAX_USERNAME 100
#define MAX_PASSWORD 100
#define MIN_PASSWORD_LENGTH 7
#define TABULA_RECTA_NO_ROWS_COLUMNS 200
#define MAX_LINE 200
#define ERROR_PASSWORD_LONG "The password must be at least 7 chars long"
#define ERROR_PASSWORD_NOT_USERNAME "The password must not contain the username"
#define ERROR_PASSWORD_SPECIAL_CHAR "The password must contain one of the following characters: {'.','_','!'}"
#define ERROR_PASSWORD_DIGITS "The password must contain digits"
#define SIGN_IN_UP "Do you want to sign in or sign up?"
#define SIGN_IN "Sign in"
#define SIGN_UP "Sign up"
#define SIGNING_IN "Signing in!"
#define SIGNING_UP "Signing up!"
#define USER_NOT_FOUND "Username doesn't exist"
#define DUPLICATE_USER "Please choose another username!"
#define INCORRECT_PASSWORD "Incorrect password"

userdata createUser(){
    userdata u;
    u.username = (char*)malloc(MAX_USERNAME*sizeof(char));
    u.password = (char*)malloc(MAX_PASSWORD*sizeof(char));
    return u;
}

void inputUserData(userdata * u){
    int sign_in_up=0,state=0,tabulaRecta[TABULA_RECTA_NO_ROWS_COLUMNS][TABULA_RECTA_NO_ROWS_COLUMNS];
    char sign;
    FILE*accounts;
    generateEncryptionDecryptionKey(tabulaRecta);
    while(!sign_in_up){
        switch(state){
            case 0: {
                printf("%s\n"
                       "a)%s\n"
                       "b)%s\n",SIGN_IN_UP,SIGN_IN,SIGN_UP);
                sign=getchar();
                getchar();
                state++;
                break;
            }
            case 1: {
                //signing in
                if(sign == 'a')signingIn(u->username,u->password,&sign_in_up,&state,tabulaRecta,accounts);
                else state++;
                break;
            }
            case 2: {
                //signing up
                signingUp(u->username,u->password,&sign_in_up,tabulaRecta,accounts);
                break;
            }
        }
    }
}
int validateUsernameSignIn(char username[],char existingUsername[]){
    if(strcmp(username,existingUsername)==0) return 1;
    else return 0;
}
int validatePasswordSignIn(char password[],char existingPassword[]){
    if(strcmp(password,existingPassword)==0) return 1;
    else return 0;
}
int validateUsernameSignUp(char username[],char existingUsername[]){
    if(strcmp(username,existingUsername)==0) return 0;
    else return 1;
}
int validatePasswordSignUp(int (*fullfillscondition)(char[]),char password[],char error[]){
    if(fullfillscondition(password)) return 1;
    else printf("%s\n",error);
    return 0;
}
int length(char password[]){
    if(strlen(password)<MIN_PASSWORD_LENGTH)return 0;
    return 1;
}
int pass_diff_username(char password[],char username[],char error[]){
    if(strstr(password,username)!=NULL){
        printf("%s\n",error);
        return 0;
    }
    return 1;
}
int pass_special_char(char password[]){
    if(strchr(password,'.')!=NULL)return 1;
    if(strchr(password,'_')!=NULL)return 1;
    if(strchr(password,'!')!=NULL)return 1;
    return 0;
}
int pass_have_digit(char password[]){
    int ok=0;
    for(int i=0;i<strlen(password);i++){
        if(isdigit(password[i]))return 1;
    }
    return 0;
}
void signingIn(char username[],char password[],int * sign_in,int *state,int tabulaRecta[][TABULA_RECTA_NO_ROWS_COLUMNS],FILE*readAccounts){
    printf("---%s\n"
           "---Username\n",SIGNING_IN);
    gets(username);
    printf("---Password\n");
    gets(password);
    //read no of accounts
    readAccounts = fopen("C:\\Users\\edian\\Desktop\\Faculta\\an1\\cp lab\\food-ordering\\accounts.txt","r");
    char line[MAX_LINE];
    int noOfAccounts;
    fgets(line,MAX_LINE,readAccounts);
    fgets(line,MAX_LINE,readAccounts);
    sscanf(line,"%d",&noOfAccounts);
    //validating account
    char existingPassword[MAX_LINE];
    char existingUsername[MAX_LINE];
    int i=1,validUser=0;
    while(!validUser && i<=noOfAccounts){
        fgets(existingUsername,MAX_LINE,readAccounts);
        existingUsername[strlen(existingUsername)-1]='\0';
        fgets(existingPassword,MAX_LINE,readAccounts);
        existingPassword[strlen(existingPassword)-1]='\0';
        if(validateUsernameSignIn(username,existingUsername)){
            validUser=1;
            decryptPassword(existingPassword,tabulaRecta);
            if(validatePasswordSignIn(password,existingPassword))(*sign_in)=1;
        }
        i++;
    }
    if(validUser&&!(*sign_in))printf("%s\n",INCORRECT_PASSWORD);
    if(!validUser) {
        printf("%s\n",USER_NOT_FOUND);
        (*state)--;
    }
}
void signingUp(char username[],char password[],int * sign_up,int tabulaRecta[][TABULA_RECTA_NO_ROWS_COLUMNS],FILE * createNewAccount){
    printf("%s\n"
           "---Username\n",SIGNING_UP);
    gets(username);
    //read no of users
    createNewAccount = fopen("C:\\Users\\edian\\Desktop\\Faculta\\an1\\cp lab\\food-ordering\\accounts.txt","r");
    char line[MAX_LINE];
    int noOfUsers;
    fgets(line,MAX_LINE,createNewAccount);
    fgets(line,MAX_LINE,createNewAccount);
    sscanf(line,"%d",&noOfUsers);
    int i=1,validUser=1;
    char existingUsername[MAX_LINE];
    while(validUser && i<=noOfUsers){
        fgets(existingUsername,MAX_LINE,createNewAccount);
        existingUsername[strlen(existingUsername)-1]='\0';
        if(!validateUsernameSignUp(username,existingUsername))validUser=0;
        fgets(line,MAX_LINE,createNewAccount);
        i++;
    }
    if(!validUser)printf("%s\n",DUPLICATE_USER);
    else {
        printf("---Password\n");
        while(*sign_up!=1){
            gets(password);
            if(validatePasswordSignUp(&length,password,ERROR_PASSWORD_LONG) &&
            pass_diff_username(password,username,ERROR_PASSWORD_NOT_USERNAME) &&
            validatePasswordSignUp(&pass_special_char,password,ERROR_PASSWORD_SPECIAL_CHAR) &&
            validatePasswordSignUp(&pass_have_digit,password,ERROR_PASSWORD_DIGITS)) {
                (*sign_up) = 1;
                //appending username and password
                createNewAccount = fopen("C:\\Users\\edian\\Desktop\\Faculta\\an1\\cp lab\\food-ordering\\accounts.txt","a+");
                fprintf(createNewAccount,"%s\n",username);
                encryptPassword(password,tabulaRecta);
                fprintf(createNewAccount,"%s\n",password);
                fclose(createNewAccount);
                //read no of users
                createNewAccount = fopen("C:\\Users\\edian\\Desktop\\Faculta\\an1\\cp lab\\food-ordering\\accounts.txt","r+");
                char line[MAX_LINE];int noOfCharsForKey,noOfAccounts;
                fgets(line,MAX_LINE,createNewAccount);
                noOfCharsForKey=strlen(line);
                fgets(line,MAX_LINE,createNewAccount);
                sscanf(line,"%d",&noOfAccounts);
                //change no of users
                noOfAccounts++;
                fseek(createNewAccount,noOfCharsForKey+1,SEEK_SET);
                fprintf(createNewAccount, "%d", noOfAccounts);
                fclose(createNewAccount);
            }
        }
    }
}
void generateEncryptionDecryptionKey(int tabulaRecta[][TABULA_RECTA_NO_ROWS_COLUMNS]){
    for(int i=' ';i<='~';i++){
        for(int j=' ';j<='~'-i+' ';j++){
            tabulaRecta[i][j]=i+j-' ';
        }
        for(int j='~'-i+' '+1;j<='~';j++){
            tabulaRecta[i][j]=j-('~'-i+1);
        }
    }
}
void encryptPassword(char password[],int tabulaRecta[][TABULA_RECTA_NO_ROWS_COLUMNS]){
    for(int a=0;a<strlen(password); a++){
        password[a]=tabulaRecta[password[a]][a + ' '];
    }
}
void decryptPassword(char password[],int tabulaRecta[][TABULA_RECTA_NO_ROWS_COLUMNS]){
    for(int a=1;a<strlen(password); a++){
        password[a]=tabulaRecta['~' - a + 1][password[a]];
    }
}