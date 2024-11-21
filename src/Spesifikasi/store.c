#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"
#include "../ADT/list_dinamis.h"

void createStore(Store *store) {
    CreateListDin(&(store->barang), 100);
    CreateListDin(&(store->antrian), 100);
}

void addItemToStore(Store *store, char *item) {
    insertLast(&(store->barang), item);
}

void addItemToQueue(Store *store, char *item) {
    insertLast(&(store->antrian), item);
}