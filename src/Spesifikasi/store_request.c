#include <stdio.h>
#include <stdlib.h>
#include "store_request.h"

// Fungsi untuk mengecek apakah barang sudah ada dalam daftar barang di toko
int isItemExistInStore(Store store, char *item) {
    for (int i = 0; i < listLength(store.barang); i++) {
        char *currentItem = ELMT(store.barang, i);
        int j = 0;

        // Bandingkan karakter per karakter
        while (currentItem[j] != '\0' && item[j] != '\0' && currentItem[j] == item[j]) {
            j++;
        }

        // Jika kedua string sama panjang dan semua karakter cocok
        if (currentItem[j] == '\0' && item[j] == '\0') {
            return 1; // Item ditemukan di toko
        }
    }
    return 0; // Item tidak ditemukan
}

// Fungsi untuk mengecek apakah barang sudah ada dalam antrian
int isItemExistInQueue(Store store, char *item) {
    for (int i = 0; i < listLength(store.barang); i++) {
        char *currentItem = ELMT(store.barang, i);
        int j = 0;

        // Bandingkan karakter per karakter
        while (currentItem[j] != '\0' && item[j] != '\0' && currentItem[j] == item[j]) {
            j++;
        }

        // Jika kedua string sama panjang dan semua karakter cocok
        if (currentItem[j] == '\0' && item[j] == '\0') {
            return 1; // Item ditemukan di antrian
        }
    }
    return 0; // Item tidak ditemukan
}

// Fungsi untuk menambah permintaan barang baru ke dalam antrian
void storeRequest(Store *store, char *item) {
    if (isItemExistInStore(*store, item)) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
    } else if (isItemExistInQueue(*store, item)) {
        printf("Barang dengan nama yang sama sudah ada di antrian!\n");
    } else {
        insertLast(&(store->barang), item);  // Menambahkan barang ke dalam antrian
        printf("Nama barang yang diminta: %s\n", item);
    }
}
