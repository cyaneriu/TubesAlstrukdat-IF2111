#include <stdio.h>
#include <stdlib.h>
#include "../ADT/mesinkarakter.h"

//TERMINAL COMMAND:
//gcc driver_mesinkarakter.c ../ADT/mesinkarakter.c -o mesinkarakter
//./mesinkarakter

int main() {
    char filename[] = "testfile.txt";

    // 1. START (stdin)
    printf("START\n");
    printf("Masukkan karakter: ");
    START();
    while (!IsEOP()) {
        printf("Karakter dibaca: '%c'\n", GetCC());
        ADV();
    }
    printf("\n");

    // 2. StartFile
    printf("StartFile (baca dari file: %s)\n", filename);
    StartFile(filename);
    if (pita == NULL) {
        printf("Gagal membuka file!\n");
    } else {
        printf("Isi file:\n");
        while (!IsEOP()) {
            printf("%c", GetCC());
            AdvFile();
        }
        printf("\n\n");
    }

    // 3. ADV dan GetCC
    printf("ADV dan GetCC\n");
    printf("Masukkan karakter: ");
    START();
    while (!IsEOP()) {
        printf("Karakter: '%c'\n", GetCC());
        ADV();
    }
    printf("\n");

    // 4. IsEOP
    printf("IsEOP\n");
    printf("Apakah akhir pita? %s\n", IsEOP() ? "Ya" : "Tidak");

    return 0;
}