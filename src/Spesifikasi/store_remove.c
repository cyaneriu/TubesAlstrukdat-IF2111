#include <stdio.h>
#include <stdlib.h>
#include "store_remove.h"
#include "store_request.h"
#include "../ADT/list_dinamis.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"

void storeRemove(Store *store) {
    printf("Input barang yang akan dihapus: ");
    StartWordInput();

    Word itemWord = currentWord;
    itemWord.TabWord[itemWord.Length] = '\0';

    boolean found = false;
    for (int i = 0; i < listLengthDin(store->barang); i++) {
        char *itemName = ELMTDin(store->barang, i);
        if (isEqualWords(itemWord, itemName)) {
            found = true;
            deleteAtDin(&(store->barang), i);
            printf("%s telah berhasil dihapus dari toko.\n", itemWord.TabWord);
            break;
        }
    }

    if (!found) {
        printf("Toko tidak menjual %s\n", itemWord.TabWord);
    }
}

