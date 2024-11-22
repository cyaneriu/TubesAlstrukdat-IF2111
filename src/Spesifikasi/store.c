#include <stdio.h>
#include <stdlib.h>
#include "store.h"
#include "store_list.h"
#include "store_request.h"
#include "store_supply.h"
#include "store_supply.h"
#include "store_remove.h"
#include "../ADT/boolean.h"
#include "../ADT/list_dinamis.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"

void createStore(Store *store) {
    CreateListDin(&(store->barang), 100);
    CreateListDin(&(store->antrian), 100);
}

void addItemToStore(Store *store, char *item) {
    insertLastDin(&(store->barang), item);
}

void addItemToQueue(Store *store, char *item) {
    insertLastDin(&(store->antrian), item);
}