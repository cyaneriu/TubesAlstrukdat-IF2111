#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store_supply.h"

void storeSupply(Store *store) {
    if (isEmpty(store->antrian)) {
        printf("Antrian permintaan kosong.\n");
        return;
    }

    char item[100];
    int price;

    copyFirst(store->antrian, item);

    printf("Apakah kamu ingin menambahkan barang %s: ", item);
    StartWordInput();

    if (IsCommandEqual(currentWord, "Terima\0")) {
        printf("Harga barang: ");
        while (scanf("%d", &price) != 1 || price <= 0) {
            printf("Harga harus berupa angka yang lebih besar dari 0!\n");
            while (getchar() != '\n');
        }

        copyFirst(store->antrian, item);  
        insertLast(&(store->barang), item);
        deleteFirst(&(store->antrian));

        printf("%s dengan harga %d telah ditambahkan ke toko.\n", item, price);
    } 

    else if (IsCommandEqual(currentWord, "Tunda\0")) {
        printf("%s dikembalikan ke antrian.\n", item);
    }
    else if (IsCommandEqual(currentWord, "Tolak\0")) {
        printf("%s dihapuskan dari antrian.\n", item);
        deleteFirst(&(store->antrian));
    }
    else {
        printf("Tindakan tidak valid.\n");
    }
}
