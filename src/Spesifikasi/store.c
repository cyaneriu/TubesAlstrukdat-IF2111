#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"
#include "../ADT/list_dinamis.h"

// Fungsi untuk membuat store baru dengan kapasitas tertentu
void createStore(Store *store) {
    CreateListDin(&(store->barang), 10);  // Misalnya kapasitas default adalah 10
}

// Fungsi untuk menambahkan barang ke dalam store
void addItemToStore(Store *store, char *item) {
    insertLast(&(store->barang), item);  // Menambah item ke dalam daftar barang
}

// Fungsi untuk menghapus barang dari store
void removeItemFromStore(Store *store, char *item) {
    int found = 0;
    for (int i = 0; i < listLength(store->barang); i++) {
        if (strcmp(ELMT(store->barang, i), item) == 0) {
            found = 1;
            // Hapus barang dari daftar
            free(store->barang.items[i]);
            for (int j = i; j < listLength(store->barang) - 1; j++) {
                store->barang.items[j] = store->barang.items[j + 1];
            }
            store->barang.size--;
            printf("%s telah berhasil dihapus.\n", item);
            break;
        }
    }
    if (!found) {
        printf("Toko tidak menjual %s\n", item);
    }
}
