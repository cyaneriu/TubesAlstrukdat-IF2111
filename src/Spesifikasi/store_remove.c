#include <stdio.h>
#include <stdlib.h>
#include "store_remove.h"
#include "../ADT/mesinkata.h"
#include "store_request.h"
#include "store.h"
#include "../ADT/list_dinamis.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"

// Fungsi untuk menghapus barang dari toko
void removeItemFromStore(Store *store) {
    printf("Nama barang yang akan dihapus: ");
    StartWordInput();

    int found = 0;
    for (int i = 0; i < listLength(store->barang); i++) {
        if (isEqualWords(currentWord, ELMT(store->barang, i))) {
            found = 1;

            // Hapus barang dari toko
            for (int j = i; j < listLength(store->barang) - 1; j++) {
                store->barang.items[j] = store->barang.items[j + 1];
            }
            store->barang.size--;
            printf("%s telah berhasil dihapus.\n", currentWord.TabWord);
            break;
        }
    }

    if (!found) {
        printf("Toko tidak menjual %s\n", currentWord.TabWord);
    }
}
