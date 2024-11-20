#ifndef STORE_H
#define STORE_H

#include "../ADT/list_dinamis.h"
#include "../ADT/boolean.h"

// Definisi struktur Store yang berisi daftar barang (ListDin)
typedef struct {
    ListDin barang;
} Store;

// Fungsi untuk membuat store baru
void createStore(Store *store);

void displayStore(Store store);

// Fungsi untuk menambahkan barang ke dalam store
void addItemToStore(Store *store, char *item);

// Fungsi untuk menghapus barang dari store
void removeItemFromStore(Store *store, char *item);

// Fungsi untuk memproses barang dari antrian permintaan
void processStoreSupply(Store *store);

// Fungsi untuk meminta barang baru ke dalam toko (Store Request)
void storeRequest(Store *store, char *item);

void removeItemFromStore(Store *store, char *item);

#endif
