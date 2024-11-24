#include <stdio.h>
#include <stdlib.h>
#include "load.h"

int wordToInt(Word word) {
    char str[MAX_LEN];
    int i;
    for (i = 0; i < word.Length; i++) {
        str[i] = word.TabWord[i];
    }
    str[i] = '\0';
    return atoi(str);
}

void wordToString(Word word, char* str) {
    int i;
    for (i = 0; i < word.Length; i++) {
        str[i] = word.TabWord[i];
    }
    str[i] = '\0';
}

void Load(char *filename, Barang barang[], int *jumlahBarang, User user[], int *jumlahUser) {
    char fullPath[100];
    char directory[100] = "../save";
    sprintf(fullPath, "%s/%s", directory, filename);
    printf(filename);
    printf(fullPath);
    StartWordFile(fullPath, 0);

    if (EndWord) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return;
    }
    *jumlahBarang = wordToInt(currentWord);
    for (int i = 0; i < *jumlahBarang; i++) {
        ADVLine(); 
        barang[i].price = wordToInt(currentWord);
        Word namaBarang = SplitWordBlank(currentWord);
        wordToString(namaBarang, barang[i].name);
    }

    ADVLine();

    *jumlahUser = wordToInt(currentWord);

   
    for (int i = 0; i < *jumlahUser; i++) {
        ADVLine();  
        user[i].money = wordToInt(currentWord);

        Word temp = SplitWordBlank(currentWord);
        Word nama = SplitWordLeftBlank(temp);
        wordToString(nama, user[i].name);

        temp = SplitWordBlank(temp);
        wordToString(temp, user[i].password);
        user[i].logged = false;
    }
    printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
}

void startLoad(char *filename) {
    Barang barang[MAX_BARANG];
    User user[MAX_USER];
    int jumlahBarang, jumlahUser;
    Load(filename, barang, &jumlahBarang, user, &jumlahUser);
    printf("%d\n", jumlahBarang);
    printf("%d\n", jumlahUser);
    printf("File berhasil dimuat.\n");
}