#ifndef STORE_H
#define STORE_H

#include "../ADT/list_dinamis.h"
#include "../ADT/boolean.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"

// Definisi struktur Store yang berisi daftar barang (ListDin)
typedef struct {
    ListDin barang;
    ListDin antrian;
} Store;

typedef struct {
    char name[MAX_LEN];  // Name of the item
    int price;           // Price of the item
} Barang;

void createStore(Store *store);

void addItemToStore(Store *store, char *item);

void addItemToQueue(Store *store, char *item);

void displayStoreMenu();

void store_running();

#endif
