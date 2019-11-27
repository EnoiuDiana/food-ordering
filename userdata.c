//
// Created by edian on 05.11.2019.
//
#include <stdio.h>
#include <string.h>
#include "userdata.h"
#include <ctype.h>
#define MIN_PASSWORD_LENGTH 7

/*int length(char password[]);
int pass_diff_username(char password[],char username[],char error[]);
int pass_special_char(char password[]);
int pass_have_digit(char password[]);
int validatePasswordSignUp(int (*fullfillscondition)(char[]),char password[],char error[]);*/

void inputUserData(char username[],char password[]){
    int sign_in_up=0,state=0;
    char sign;
    char ERROR_PASSWORD_LONG[] = "The password must be at least 7 chars long",
            ERROR_PASSWORD_NOT_USERNAME[] = "The password must not contain the username",
            ERROR_PASSWORD_SPECIAL_CHAR[] = "The password must contain one of the following characters: {'.','_','!'}",
            ERROR_PASSWORD_DIGITS[] = "The password must contain digits",
            SIGN_IN_UP[] = "Do you want to sign in or sign up?",
            SIGN_IN[] = "Sign in",
            SIGN_UP[] = "Sign up",
            SIGNING_IN[] = "Signing in!",
            SIGNING_UP[] = "Signing up!",
            USER_NOT_FOUND[] = "Username doesn't exist",
            DUPLICATE_USER[] = "Please choose another username!",
            INCORRECT_PASSWORD[] = "Incorrect password";

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
                //signin in
                if(sign == 'a')signinIn(username,password,&sign_in_up,&state,SIGNING_IN,INCORRECT_PASSWORD,USER_NOT_FOUND);
                else state++;
                break;
            }
            case 2: {
                //signin up
                signinUp(username,password,&sign_in_up,SIGNING_UP,DUPLICATE_USER,ERROR_PASSWORD_LONG,
                         ERROR_PASSWORD_NOT_USERNAME,ERROR_PASSWORD_SPECIAL_CHAR,ERROR_PASSWORD_DIGITS);
                break;
            }
        }
    }
}
int validateUsernameSignIn(char username[]){
    if(strcmp(username,"admin")==0) return 1;
    else return 0;
}
int validatePasswordSignIn(char password[]){
    if(strcmp(password,"admin")==0) return 1;
    else return 0;
}
int validateUsernameSignUp(char username[]){
    if(strcmp(username,"admin")==0) return 0;
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
void signinIn(char username[],char password[],int * sign_in,int *state,char message[],
              char err_pass[],char err_user[]){
    printf("---%s\n"
           "---Username\n",message);
    gets(username);
    printf("---Password\n");
    gets(password);
    if(validateUsernameSignIn(username)&&validatePasswordSignIn(password))(*sign_in)=1;
    if(validateUsernameSignIn(username)&&!validatePasswordSignIn(password))printf("%s\n",err_pass);
    if(!validateUsernameSignIn(username)){
        printf("%s\n",err_user);
        (*state)--;
    }
}
void signinUp(char username[],char password[],int * sign_up,char message[],char err_user[],char err_length[],
              char err_pass_not_username[],char err_special_char[],char err_digits[]){

    printf("%s\n"
           "---Username\n",message);
    gets(username);
    if(!validateUsernameSignUp(username))printf("%s\n",err_user);
    else {
        printf("---Password\n");
        gets(password);
        if(validatePasswordSignUp(&length,password,err_length) &&
           pass_diff_username(password,username,err_pass_not_username) &&
           validatePasswordSignUp(&pass_special_char,password,err_special_char) &&
           validatePasswordSignUp(&pass_have_digit,password,err_digits) ){
            (*sign_up)=1;
        }

    }
}



