#include <stdio.h>
#include "register.h"
#include "load.h"

#define MAX_USER 50
#define FILENAME "default.txt"

// fungsi buat ngecek username yg diinput sesuai ato ngga
boolean usernamevalid(char usernames[][MAX_LEN], int userCount, Word usernameWord) {
    for (int i = 0; i < userCount; i++) {
        Word fileWord = stringToWord(usernames[i]);
        char usernamedest[MAX_LEN];
        wordToString(usernameWord, usernamedest);
        // skenario kalau username udah ada di file txt
        if (isEqualWords(fileWord, usernamedest)) {
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
    Barang barang1[MAX_BARANG];
    User user1[MAX_USER];
    int jumlahBarang = 0;
    int jumlahUser = 0;

    // manggil fungsi load
    Load(FILENAME, barang1, &jumlahBarang, user1, &jumlahUser);

    printf("Masukkan username: ");
    StartWordInput();
    CopyWordinput();
    Word usernameWord = currentWord;
    if(usernameWord.Length >= MAX_LEN){
        printf("Username is too long!\n");
        return;
    }

    printf("Masukkan password:");
    StartWordInput();
    CopyWordinput();
    Word passwordWord = currentWord;
    if (passwordWord.Length >= MAX_LEN){
        printf("Password is too long!\n");
        return;
    }

    // cek input memenuhi satukata ga
    if (!satukata(usernameWord) || !satukata(passwordWord)) {
        printf("Username dan password harus satu kata!\n");
        return;
    }

    // looping struct user buat cek udh ada blm usn itu
    for (int i = 0; i < jumlahUser; i++) {
        if (isEqualWords(stringToWord(user1[i].name), usernameWord.TabWord)) {
            printf("Akun dengan username ");
            DisplayWord(usernameWord);
            printf(" sudah ada. Silakan LOGIN untuk melanjutkan.\n");
            return;
        }
    }

    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        printf("File tidak bisa dibuka untuk menulis!\n");
        return;
    }
    char usernameStr[MAX_LEN];
    char passwordStr[MAX_LEN];
    // convert ke string
    wordToString(usernameWord, usernameStr); 
    wordToString(passwordWord, passwordStr); 
    // masukin ke file
    fprintf(file, "0\t%s\t%s\n", usernameStr, passwordStr); // Tambahkan user baru
    fclose(file);
    printf("Akun dengan username ");
    DisplayWord(usernameWord);
    printf(" telah berhasil dibuat dengan saldo awal 0. Silakan LOGIN untuk melanjutkan.\n");
}