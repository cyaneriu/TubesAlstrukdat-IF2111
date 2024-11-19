#include <stdio.h>
#include <string.h>
#include "store_remove.h"

// Fungsi untuk menghapus barang dari toko
void removeItemFromStore(Store *store, char *item) {
    int found = 0;
    for (int i = 0; i < listLength(store->barang); i++) {
        if (strcmp(ELMT(store->barang, i), item) == 0) {
            found = 1;
            free(store->barang.items[i]);
            for (int j = i; j < listLength(store->barang) - 1; j++) {
                store->barang.items[j] = store->barang.items[j + 1];
            }
            store->barang.size--;
            printf("%s telah berhasil dihapus.\n", item);
            break;
        }
    }
    if (!found) {
        printf("Toko tidak menjual %s\n", item);
    }
}
