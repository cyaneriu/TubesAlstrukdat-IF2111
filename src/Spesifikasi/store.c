#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"
#include "../ADT/list_dinamis.h"

// Fungsi untuk membuat store baru dengan kapasitas tertentu
void createStore(Store *store) {
    CreateListDin(&(store->barang), 100);  // Misalnya kapasitas default adalah 10
}

// Fungsi untuk menambahkan barang ke dalam store
void addItemToStore(Store *store, char *item) {
    insertLast(&(store->barang), item);  // Menambah item ke dalam daftar barang
}
