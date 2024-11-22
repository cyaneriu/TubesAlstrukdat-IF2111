#include <stdio.h>
#include <stdlib.h>
#include "store.h"
#include "store_supply.h"

void storeSupply(Store *store) {
    if (isEmptyDin(store->antrian)) {
        printf("Antrian permintaan kosong.\n");
        return;
    }

    char item[100];
    int price;

    copyFirstDin(store->antrian, item);

    printf("Apakah kamu ingin menambahkan barang %s: ", item);
    StartWordInput();

    if (IsCommandEqual(currentWord, "Terima")) {
        while (price <= 0) {
            printf("Harga barang: ");
            StartWordInput();

            price = 0;
            for (int i = 0; i < currentWord.Length; i++) {
                if (currentWord.TabWord[i] < '0' || currentWord.TabWord[i] > '9') {
                    price = -1;
                    break;
                }
                price = price * 10 + (currentWord.TabWord[i] - '0');
            }
            if (price <= 0) {
                printf("Harga harus berupa angka yang lebih besar dari 0!\n");
            } while (getchar() != '\n');
        }

        copyFirstDin(store->antrian, item);  
        insertLastDin(&(store->barang), item);
        deleteFirstDin(&(store->antrian));

        printf("%s dengan harga %d telah ditambahkan ke toko.\n", item, price);
    } 

    else if (IsCommandEqual(currentWord, "Tunda\0")) {
        printf("%s dikembalikan ke antrian.\n", item);
    }
    else if (IsCommandEqual(currentWord, "Tolak\0")) {
        printf("%s dihapuskan dari antrian.\n", item);
        deleteFirstDin(&(store->antrian));
    }
    else {
        printf("Tindakan tidak valid.\n");
    }
}
