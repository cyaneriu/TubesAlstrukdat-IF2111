#ifndef STORE_H
#define STORE_H
#include "store.h"
#include "../ADT/boolean.h"
#include "../ADT/list_dinamis.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"

typedef struct {
    ListDin barang;
    ListDin antrian;
} Store;

typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

void createStore(Store *store);

void addItemToStore(Store *store, char *item);

void addItemToQueue(Store *store, char *item);

#endif
