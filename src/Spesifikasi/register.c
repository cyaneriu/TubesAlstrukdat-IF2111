#include <stdio.h>
#include "register.h"

#define MAX_USER 100
#define FILENAME "user_data.txt"

// fungsi buat ngecek username yg diinput sesuai ato ngga
boolean usernamevalid(char usernames[][MAX_LEN], int userCount, Word usernameWord) {
    for (int i = 0; i < userCount; i++) {
        Word fileWord = stringToWord(usernames[i]);
        // skenario kalau username udah ada di file txt
        if (IsWordEqual(fileWord, usernameWord)) {
            return false; 
        }
    }
    return true;
}

// fungsi buat ngecek username yg di input satu kata atau engga
boolean satukata(Word masukan) {
    for (int i = 0; i < masukan.Length; i++) {
        // skenario kalo ada spasi 
        if (masukan.TabWord[i] == ' ' || masukan.TabWord[i] == '\t') {
            return false; 
        }
    }
    return true;
}

void registeruser() {
    Word usernameWord, passwordWord;
    char usernames[MAX_USER][MAX_LEN];
    int userCount = 0;

    // buka file 
    FILE *file = fopen(FILENAME, "r");
    if (file) {
        // format file uang - username - password
        while (fscanf(file, "%*d %s %*s", usernames[userCount]) != EOF) {
            userCount++; // ngitung jumlah user yg udh ada di file
        }
        fclose(file);
    }

    printf("Enter username: "); 
    StartWordInput(); // input username pake ADT mesinkata
    CopyWordinput();
    usernameWord = currentWord; 
    if (usernameWord.Length >= MAX_LEN) { // cek apakah input melebihi MAX_LEN (50)
        printf("Username melebihi batas max!\n");
        return;
    }

    printf("Enter password: ");
    StartWordInput(); // input username pake ADT mesinkata
    CopyWordinput();
    passwordWord = currentWord; 
    if (passwordWord.Length >= MAX_LEN) { // cek password melebihi MAX_LEN (50) ga
        printf("Password melebihi batas max!\n");
        return;
    }

    // skenario kalo username ato password yg dibikin bkn 1 kata
    if (!satukata(usernameWord) || !satukata(passwordWord)) {
        printf("Username dan password tidak memenuhi ketentuan!\n");
        return;
    }

    // skenario kalo username yg dibikin udh ada di file txt
    if (!usernamevalid(usernames, userCount, usernameWord)) {
        char usernameStr[MAX_LEN];
        wordToString(usernameWord, usernameStr);
        printf("Akun dengan username %s telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n", usernameStr);
        return;
    }

    // ngebuka file buat masukin username yg baru
    file = fopen(FILENAME, "a");
    if (!file) {
        printf("File tidak bisa dibuka!.\n");
        return;
    }

    // save data user yg baru ke file dengan uang di set menjadi 0 
    char usernameStr[MAX_LEN], passwordStr[MAX_LEN];
    wordToString(usernameWord, usernameStr); // ngeconvert usn biar jd string
    wordToString(passwordWord, passwordStr); // ngeconvert password biar jd string
    fprintf(file, "0\t%s\t%s\n", usernameStr, passwordStr); // uang di set 0 
    fclose(file); // close file

    printf("Akun dengan username %s telah berhasil dibuat dengan saldo awal 0. Silakan LOGIN untuk melanjutkan.\n", usernameStr);
}
