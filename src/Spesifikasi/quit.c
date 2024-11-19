#include "save.h"
#include <stdio.h>

void quit(char *filename, Barang barang[], int jumlahBarang, User user[], int jumlahUser){
    printf(">>>> QUIT\n");
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? \n");

    int input;
    printf(">> ");
    scanf("%d", &input);

    if (input == 'Y' || input == 'y') {
        Barang barang[MAX_BARANG];
        User user[MAX_USER];
        int jumlahBarang, jumlahUser;

        Save("coba.txt", barang, jumlahBarang, user, jumlahUser);
        printf("Data berhasil disimpan!\n");
    } else if (input == 'N' || input == 'n'){
        printf("Kamu keluar dari PURRMART.\n");
    }
    printf("Dadah ^_^/\n");
    exit(0);
}