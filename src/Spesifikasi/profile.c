#include <stdio.h>
#include "profile.h"

void welcome_user(){
    printf("  _   _      _ _         \n");
    printf(" | | | | ___| | | ___    \n");
    printf(" | |_| |/ _ \\ | |/ _ \\   \n");
    printf(" |  _  |  __/ | | (_) |  \n");
    printf(" |_| |_|\\___|_|_|\\___/   \n");
    printf("\n");
}

void user_profile(User *currentUser){
    if (currentUser->logged){
        welcome_user();
        printf(">> PROFILE\n");
        printf("Name: %s\n", (*currentUser).name);
        printf("Money: %d\n", (*currentUser).money);
    }
    else{
        printf("Silahkan LOGIN terlebih dahulu :)\n");
    }
}