#ifndef STORE_H
#define STORE_H

#include "ADT/list_dinamis.h"
#include "ADT/boolean.h"

typedef struct {
    ListDin barang; // Barang dalam toko
} Store;

// Inisialisasi store
void initStore(Store *store, int capacity);

// Menampilkan daftar barang di toko
void displayStore(Store store);

#endif
