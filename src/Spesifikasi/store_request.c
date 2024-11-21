#include <stdio.h>
#include <stdlib.h>
#include "store_request.h"
#include "../ADT/mesinkata.h"

// Fungsi untuk mengecek apakah dua kata sama
boolean isEqualWords(Word word1, char *str) {
    int i = 0;
    while (i < word1.Length && str[i] != '\0' && word1.TabWord[i] == str[i]) {
        i++;
    }
    return (i == word1.Length && str[i] == '\0');
}

boolean isItemInStore(Store store, Word item) {
    for (int i = 0; i < listLength(store.barang); i++) {
        if (isEqualWords(item, ELMT(store.barang, i))) {
            return true;
        }
    }
    return false;
}

boolean isItemInQueue(Store store, Word item) {
    for (int i = 0; i < listLength(store.barang); i++) {
        if (isEqualWords(item, ELMT(store.barang, i))) {
            return true;
        }
    }
    return false;
}

void storeRequest(Store *store) {
    printf("Masukkan nama barang yang diminta: ");
    StartWordInput();

    while (getchar() != '\n'); 
    Word item = currentWord;
    item.TabWord[item.Length] = '\0';

    if (isItemInStore(*store, item)) {
        printf("Barang dengan nama yang sama sudah ada di toko!\n");
    } else if (isItemInQueue(*store, item)) {
        printf("Barang dengan nama yang sama sudah ada di antrian!\n");
    } else {
        insertLast(&(store->barang), item.TabWord);
        printf("Nama barang yang diminta: %s\n", item.TabWord);
    }
}
