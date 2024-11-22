#include <stdio.h>
#include <stdlib.h>
#include "store_request.h"
#include "../ADT/mesinkata.h"

boolean isItemInStore(Store store, Word item) {
    for (int i = 0; i < listLengthDin(store.barang); i++) {
        if (isEqualWords(item, ELMTDin(store.barang, i))) {
            return true;
        }
    }
    return false;
}

boolean isItemInQueue(Store store, Word item) {
    for (int i = 0; i < listLengthDin(store.antrian); i++) {
        if (isEqualWords(item, ELMTDin(store.antrian, i))) {
            return true;
        }
    }
    return false;
}

void storeRequest(Store *store) {
    printf("Masukkan nama barang yang diminta: ");
    StartWordInput();
    
    Word item = currentWord;
    item.TabWord[item.Length] = '\0';
    if (currentWord.Length > 0 && currentWord.TabWord[currentWord.Length - 1] == '\n') {
                currentWord.TabWord[currentWord.Length - 1] = '\0';
    }

    if (isItemInStore(*store, item)) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
    } else if (isItemInQueue(*store, item)) {
        printf("Barang dengan nama yang sama sudah ada di antrian!\n");
    } else {
        insertLastDin(&(store->antrian), item.TabWord);
    }
}
