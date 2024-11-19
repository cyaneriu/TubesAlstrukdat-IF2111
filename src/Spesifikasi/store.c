#include <stdio.h>
#include "store.h"

// Inisialisasi store
void initStore(Store *store, int capacity) {
    CreateListDin(&(store->barang), capacity);
}

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