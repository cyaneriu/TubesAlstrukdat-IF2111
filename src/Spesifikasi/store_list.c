#include <stdio.h>
#include "store.h"
#include "store_list.h"

void displayStore(Store store) {
    if (isEmptyDin(store.barang)) {
        printf("TOKO KOSONG\n");
    } else {
        printf("List barang yang ada di toko:\n");
        for (int i = 0; i < listLengthDin(store.barang); i++) {
            Barang * item = ELMTDin(store.barang, i);
            printf("- %s\n", item->name, item->price);
        }
    }
}


void displayStoreQueue(Store store) {
    if (isEmptyQueue(store.antrian)) {
        printf("ANTRIAN KOSONG\n");
    } else {
        printf("List barang yang ada di antrian:\n");
        int idx = store.antrian.idxHead;
        while (true) {
            printf("- %s\n", store.antrian.buffer[idx]);
            if (idx == store.antrian.idxTail) break;
            idx = (idx + 1) % CAPACITY_QUEUE;
        }
    }
}
