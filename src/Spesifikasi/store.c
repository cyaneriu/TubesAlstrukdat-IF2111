#include <stdio.h>
#include <stdlib.h>
#include "store.h"
#include "store_list.h"
#include "store_request.h"
#include "store_supply.h"
#include "store_supply.h"
#include "store_remove.h"
#include "load.h"
#include "../ADT/boolean.h"
#include "../ADT/list_dinamis.h"
#include "../ADT/queue.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"

void createStore(Store *store) {
    CreateListDin(&(store->barang), 100);
    CreateQueue(&(store->antrian));
}

void addItemToStore(Store *store, Barang item) {
    insertLastDin(&(store->barang), item.name); 
}

void loadToStore(Store *store) {
    int jumlahBarang = wordToInt(currentWord);
    for (int i = 0; i < jumlahBarang; i++) {
        ADVLine();

        Barang item;
        item.price = wordToInt(currentWord);

        Word namaBarang = SplitWordBlank(currentWord);
        wordToString(namaBarang, item.name);
        addItemToStore(store, item);
    }
}

void addItemToQueue(Store *store, char *item) {
    /*if (isFull(store->antrian)) {
        expandQueue(&(store->antrian));
    }*/
    enqueue(&(store->antrian), item);
}