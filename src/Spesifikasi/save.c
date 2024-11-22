#include "save.h"
#include <stdio.h>
#include <stdlib.h>

void startWriteFile(char *filename) {
    pita = fopen(filename, "w");
    if (pita == NULL) {
        printf("File tidak dapat dibuka.\n");
    }
}
void Save(char *filename, Barang barang[], int jumlahBarang, User user[], int jumlahUser) {
    char fullPath[100];
    char directory[100] = "../save";
    sprintf(fullPath, "%s/%s", directory, filename);
    startWriteFile(fullPath); 

    char jumlahBarangStr[MAX_LEN];
    sprintf(jumlahBarangStr, "%d", jumlahBarang); 
    for (int i = 0; i < stringLen(jumlahBarangStr); i++) {
        fprintf(pita, "%c", jumlahBarangStr[i]); 
        }
    fprintf(pita, "\n"); 

    for (int i = 0; i < jumlahBarang; i++) {
        char harga[MAX_LEN];
        sprintf(harga, "%d", barang[i].price); 
        for (int j = 0; j < stringLen(harga); j++) {
            fprintf(pita, "%c", harga[j]); 
        }
        fprintf(pita, " "); 
        for (int k = 0; k < stringLen(barang[i].name); k++) {
            fprintf(pita, "%c", barang[i].name[k]); 
        }
        fprintf(pita, "\n"); 
    }

    char jumlahUserStr[MAX_LEN];
    sprintf(jumlahUserStr, "%d", jumlahUser); 
    for (int i = 0; i < stringLen(jumlahUserStr); i++) {
        fprintf(pita, "%c", jumlahUserStr[i]); 
    }
    fprintf(pita, "\n"); 


    for (int i = 0; i < jumlahUser; i++) {
        char moneyStr[MAX_LEN];
        sprintf(moneyStr, "%d", user[i].money); 
        for (int j = 0; j < stringLen(moneyStr); j++) {
            fprintf(pita, "%c", moneyStr[j]); 
        }
        fprintf(pita, " "); 
        for (int k = 0; k < stringLen(user[i].name); k++) {
            fprintf(pita, "%c", user[i].name[k]); 
        }
        fprintf(pita, " "); 
        for (int l = 0; l < stringLen(user[i].password); l++) {
            fprintf(pita, "%c", user[i].password[l]); 
        }
        fprintf(pita, "\n"); 
    }

    fclose(pita); 
    printf("Data berhasil disimpan ke  %s\n", filename);

}