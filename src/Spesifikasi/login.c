#include "login.h"
#include <stdio.h>

void login(User *currentUser, User users[], int userCount) {
    if ((*currentUser).logged) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", currentUser->name);
        return;
    }
    // input for username sama password using mesinkata.h
    Word usernameWord, passwordWord;
    boolean flag = false;

    printf("Username: ");
    StartWordInput(); // user menginput username
    usernameWord = currentWord; // proses make mesin kata

    printf("Password: ");
    StartWordInput(); // user menginput password
    passwordWord = currentWord; // proses make mesin kata

    for (int i = 0; i < userCount; i++) {
        char * storedusn = users[i].name;
        char * storedpass = users[i].password;

        if (isEqualWords(usernameWord, storedusn)) {
            if (isEqualWords(passwordWord, storedpass)){
                wordToString(usernameWord, (*currentUser).name); // Store username
                wordToString(passwordWord, (*currentUser).password); // Store password
                (*currentUser).logged = true;
                printf("Anda telah login ke PURRMART sebagai %s.\n", (*currentUser).name);
                flag = true;
                break;
            } 
            // condition kalo password ato username yg dimasukin salah
            else{
                printf("Username atau password salah.\n");
                flag = true;
                break;
            }
        }
    }
}