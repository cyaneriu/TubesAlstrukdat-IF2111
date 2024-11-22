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
    //printf("After input: '%s' (length: %d)\n", currentWord.TabWord, currentWord.Length);

    while (getchar() != '\n'); 
    Word item = currentWord;
    item.TabWord[item.Length] = '\0';
    if (item.Length > 0 && item.TabWord[item.Length - 1] == '\n') {
                item.TabWord[item.Length - 1] = '\0';
    }

    boolean found = false;

    for (int i = 0; i < listLengthDin(store->barang); i++) {
        if (isEqualWords(item, ELMTDin(store->barang, i))) {
            found = true;
            deleteAtDin(&(store->barang), i);
            printf("%s telah berhasil dihapus.\n", item.TabWord);
            break;
        }
    }

    if (!found) {
        printf("Toko tidak menjual %s\n", item.TabWord);
    }
}

