#include <stdio.h>
#include "store.h"
#include "store_list.h"

// Menampilkan daftar barang di toko
void displayStore(Store store) {
    if (isEmpty(store.barang)) {
        printf("TOKO KOSONG\n");
    } else {
        printf("List barang yang ada di toko:\n");
        for (int i = 0; i < listLength(store.barang); i++) {
            printf("- %s\n", ELMT(store.barang, i));
        }
    }
}

void displayQueue(Store store) {
    if (isEmpty(store.antrian)) {
        printf("ANTRIAN KOSONG\n");
    } else {
        printf("List barang yang ada di antrian:\n");
        for (int i = 0; i < listLength(store.antrian); i++) {
            printf("- %s\n", ELMT(store.antrian, i));
        }
    }
}