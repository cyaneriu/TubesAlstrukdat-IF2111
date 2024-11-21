#ifndef LOGIN_H
#define LOGIN_H

#include "login.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "boolean.h"
#include <stdio.h>

typedef struct {
    char username[MAX_LEN];
    char password[MAX_LEN];
    boolean logged;
} User;

void login(User *user, const char *filename) {
    if ((*user).logged) {
        printf("Anda masih tercatat sebagai %s. Silakan LOGOUT terlebih dahulu.\n", (*user).username);
        return;
    }

    // input for username sama password using mesinkata.h
    Word usernameWord, passwordWord;
    char fileUsername[MAX_LEN], filePassword[MAX_LEN];
    boolean flag = false;

    printf("Username: ");
    StartWordInput(); // user menginput username
    usernameWord = currentWord; // proses make mesin kata

    printf("Password: ");
    StartWordInput(); // user menginput password
    passwordWord = currentWord; // proses make mesinkata

    FILE *file = fopen(filename, "r"); // membuka file txt
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    // nge sync data username dan password yang di input user sama yang ada di file
    while (fscanf(file, "%s %s", fileUsername, filePassword) != EOF) {
        Word fileUsernameWord = stringToWord(fileUsername);
        Word filePasswordWord = stringToWord(filePassword);
        // cek username sama password sama kek yg ada di file ga
        if (IsWordEqual(usernameWord, fileUsernameWord)) { 
            if (IsWordEqual(passwordWord, filePasswordWord)) { 
                wordToString(usernameWord, (*user).username); // Store username
                wordToString(passwordWord, (*user).password); // Store password
                (*user).logged = true;
                // karena udh terdeteksi login jd boolean berubah jd true
                printf("Anda telah login ke PURRMART sebagai %s.\n", (*user).username);
                flag = true;
                break;
            } else {
                printf("Username atau password salah.\n");
                flag = true;
                break;
            }
        }
    }

    if (!flag) {
        printf("Username atau password salah.\n");
    }

    fclose(file);
}

#endif
