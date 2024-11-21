#include <stdio.h>
#include <stdlib.h>
#include "store_remove.h"
#include "../ADT/mesinkata.h"
#include "store_request.h"
#include "store.h"
#include "../ADT/list_dinamis.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"

void storeRemove(Store *store) {
    printf("Nama barang yang akan dihapus: ");
    StartWordInput();

    boolean found = false;

    for (int i = 0; i < listLength(store->barang); i++) {
        if (isEqualWords(currentWord, ELMT(store->barang, i))) {
            found = true;
            char item[100];
            copyFirst(store->barang, item); 
            deleteAt(&(store->barang), item);
            printf("%s telah berhasil dihapus.\n", currentWord.TabWord);
            break;
        }
    }

    if (!found) {
        printf("Toko tidak menjual %s\n", currentWord.TabWord);
    }
}

