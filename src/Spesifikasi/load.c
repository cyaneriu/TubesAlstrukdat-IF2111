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

    StartWordFile(filename, 0);

    if (EndWord) {
        printf("File tidak dapat dibuka.\n");
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
    }
}
