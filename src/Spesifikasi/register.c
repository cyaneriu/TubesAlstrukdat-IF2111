#include <stdio.h>
#include <stdlib.h>
#include "register.h"
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "boolean.h"
#include "load.h"
#include "save.h"

#define MAX_USER 100
#define FILENAME "user_data.txt"

boolean usernamevalid(char usernames[][NMax], int userCount, const char *username) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(usernames[i], username) == 0) {
            return false;
        }
    }
    return true;
}

boolean satukata(const char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ' || input[i] == '\t') {
            return false;
        }
    }
    return true;
}

void registeruser() {
    char username[NMax];
    char password[NMax];
    char usernames[MAX_USER][NMax];
    int userCount = 0;

    FILE *file = fopen(FILENAME, "r");
    if (file) {
        while (fscanf(file, "%*d %s %s", usernames[userCount], password) != EOF) {
            userCount++;
        }
        fclose(file);
    }
    // user memasukkan username
    printf("Enter username: ");
    StartWordInput();
    CopyWordinput();
    if (currentWord.Length >= NMax) {
        printf("Akun gagal dibuat, username mencapai panjang max!\n");
        return;
    }
    copyString(username, currentWord.TabWord, NMax);
    // user memasukkan password
    printf("Enter password: ");
    StartWordInput();
    CopyWordinput();
    if (currentWord.Length >= NMax) {
        printf("Akun gagal dibuat, password mencapai panjang max!\n");
        return;
    }
    copyString(password, currentWord.TabWord, NMax);
    // skenario apabila user memasukkan username atau password lebih dari satu kata
    if (!satukata(username) || !satukata(password)) {
        printf("Akun gagal dibuat! Tolong masukkan username dan password yang sesuai.\n");
        return;
    }
    // skenario apabila username memasukkan username yang sudah terdaftar di file txt
    if (!usernamevalid(usernames, userCount, username)) {
        printf("Akun dengan username %s gagal dibuat. Silahkan lakukan REGISTER ulang!\n", username);
        return;
    }

    file = fopen(FILENAME, "a");
    if (!file) {
        printf("File tidak bisa dibuka!.\n");
        return;
    }
    fprintf(file, "0\t%s\t%s\n", username, password);
    fclose(file);

    printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan\n", username);
}
