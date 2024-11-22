#include <stdio.h>
#include "store.h"
#include "store_list.h"

// Menampilkan daftar barang di toko
void displayStore(Store store) {
    if (isEmptyDin(store.barang)) {
        printf("TOKO KOSONG\n");
    } else {
        printf("List barang yang ada di toko:\n");
        for (int i = 0; i < listLengthDin(store.barang); i++) {
            printf("- %s\n", ELMTDin(store.barang, i));
        }
    }
}

void displayStoreQueue(Store store) {
    if (isEmptyDin(store.antrian)) {
        printf("ANTRIAN KOSONG\n");
    } else {
        printf("List barang yang ada di antrian:\n");
        for (int i = 0; i < listLengthDin(store.antrian); i++) {
            printf("- %s\n", ELMTDin(store.antrian, i));
        }
    }
}