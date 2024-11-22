#include <stdio.h>
#include <stdlib.h>
#include "store.h"
#include "store_supply.h"

void storeSupply(Store *store) {
    if (isEmptyQueue(store->antrian)) {
        printf("Antrian permintaan kosong.\n");
        return;
    }

    char itemName[MAX_LEN_QUEUE];
    copyFirstQueue(store->antrian, itemName);

    printf("Apakah kamu ingin menambahkan barang %s? (Terima/Tunda/Tolak): ", itemName);
    StartWordInput();

    if (IsCommandEqual(currentWord, "Terima\0")) {
        int price = -1;
        while (price <= 0) {
            printf("Harga barang: ");
            StartWordInput();
            price = wordToInt(currentWord);

            if (price <= 0) {
                printf("Harga harus berupa angka yang lebih besar dari 0!\n");
            }
        }

        Barang newBarang;
        wordToString(stringToWord(itemName), newBarang.name);
        newBarang.price = price;

        addItemToStore(store, newBarang);
        dequeue(&(store->antrian), itemName);

        printf("%s dengan harga %d telah ditambahkan ke toko.\n", itemName, price);
    } else if (IsCommandEqual(currentWord, "Tunda\0")) {
        printf("%s dikembalikan ke antrian.\n", itemName);
    } else if (IsCommandEqual(currentWord, "Tolak\0")) {
        printf("%s dihapus dari antrian.\n", itemName);
        dequeue(&(store->antrian), itemName);
    } else {
        printf("Perintah gagal. Silakan coba lagi.\n");
    }
}
