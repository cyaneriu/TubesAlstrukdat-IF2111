#include "save.h"
#include <stdio.h>
#include <stdlib.h>

void startWriteFile(char *filename) {
    pita = fopen(filename, "w");
    if (pita == NULL) {
        printf("File tidak dapat dibuka.\n");
    }
}
void Save(char *filename, Barang barang[], int *jumlahBarang, User user[], int *jumlahUser) {
    char fullPath[100];
    char directory[100] = "../save";
    sprintf(fullPath, "%s/%s", directory, filename);
    startWriteFile(fullPath); 
    fprintf(pita, "%d\n", *jumlahBarang);

    for (int i = 0; i < *jumlahBarang; i++) {
        fprintf(pita, "%d %s\n", barang[i].price, barang[i].name);
    }

    fprintf(pita, "%d\n", *jumlahUser);
    int x = *jumlahUser - 1;
    for (int i = 0; i < *jumlahUser; i++) {
        if (i != x) {
            fprintf(pita, "%d %s %s\n", user[i].money, user[i].name, user[i].password);
        } else {
            fprintf(pita, "%d %s %s", user[i].money, user[i].name, user[i].password);
        }
    }

    fclose(pita); 
    printf("Data berhasil disimpan ke  %s\n", filename);

}

int startSave(char * filename, Barang barang[], int * jumlahBarang, User user[], int * jumlahUser) {
    Save(filename, barang, jumlahBarang, user, jumlahUser);
    printf("File berhasil dimuat.\n");
    return *jumlahBarang;
}