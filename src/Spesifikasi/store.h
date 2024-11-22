#ifndef STORE_H
#define STORE_H
#include "store.h"
#include "../ADT/boolean.h"
#include "../ADT/list_dinamis.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"
#include "load.h"

typedef struct {
    ListDin barang;
    ListDin antrian;
} Store;

void createStore(Store *store);

void addItemToStore(Store *store, Barang *name);

void addItemToQueue(Store *store, Barang *name);

#endif
