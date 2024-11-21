#include <stdio.h>
#include <stdlib.h>
#include "quit.h"

void quit(){
    char *filename;
    User user[MAX_USER]; 
    Barang barang[MAX_BARANG];
    int jumlahBarang;
    int jumlahUser;

    printf(">>>> QUIT\n");
    printf("Apakah kamu ingin menyimpan data sesi sekarang (Y/N)? \n");

    char input;
    printf(">> ");
    scanf(" %c", &input);

    if (input == 'Y' || input == 'y') {
        Save(filename, barang, jumlahBarang, user, jumlahUser);
    } else if (input == 'N' || input == 'n'){
        printf("Kamu keluar dari PURRMART.\n\n");
    }
    printf("Dadah ^_^/\n");
    exit(0);
}