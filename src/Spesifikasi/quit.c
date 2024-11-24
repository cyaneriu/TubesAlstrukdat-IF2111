#include <stdio.h>
#include <stdlib.h>
#include "quit.h"

void quit(char * filename, Barang barang[MAX_BARANG], int *jumlahBarang, User user[MAX_USER], int *jumlahUser) {
    printf(">>>> QUIT\n");
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? \n");

    char input;
    printf(">> ");
    scanf(" %c", &input);

    if (input == 'Y' || input == 'y') {
        printf("Masukkan nama file penyimpanan: ");
        StartCommand();
        wordToString(currentCommand, filename);
        Save(filename, barang, jumlahBarang, user, jumlahUser);
    } else if (input == 'N' || input == 'n'){
        printf("Data tidak disimpan.\n");
    }
    printf("Dadah ^_^/\n");
    exit(0);
}