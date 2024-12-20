#ifndef STORE_H
#define STORE_H
#include "load.h"
#include "../ADT/boolean.h"
#include "../ADT/list_dinamis.h"
#include "../ADT/queue.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"

typedef struct {
    ListDin barang;
    Queue antrian;
} Store;

void createStore(Store *store);

void addItemToStore(Store *store, Barang item);

void loadToStore(Store *store);

void addItemToQueue(Store *store, char *item);

#endif
