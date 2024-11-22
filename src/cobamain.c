#include <stdio.h>
#include <stdlib.h>
#include "spesifikasi/store.h"
#include "ADT/list_dinamis.h"
#include "ADT/mesinkata.h"
#include "ADT/mesinkarakter.h"

void displayStoreMenu() {
    printf("\n=== STORE MENU ===\n");
    printf("1. STORE LIST\n");
    printf("2. STORE REQUEST\n");
    printf("3. STORE SUPPLY\n");
    printf("4. STORE REMOVE\n");
    printf("5. EXIT\n");
}

int main() {
    Store store;
    createStore(&store);
    boolean store_running = true;
    displayStoreMenu();

    while (store_running) {
        printf(">> ");
        StartWordInput();

        if (IsCommandEqual(currentWord, "STORE LIST\0")) {
            displayStore(store);
            printf("\n");
            displayStoreQueue(store);
            printf("\n");
        } else if (IsCommandEqual(currentWord, "STORE REQUEST\0")) {
            storeRequest(&store);
        } else if (IsCommandEqual(currentWord, "STORE SUPPLY\0")) {
            storeSupply(&store);
        } else if (IsCommandEqual(currentWord, "STORE REMOVE\0")) {
            storeRemove(&store);
        } else if (IsCommandEqual(currentWord, "EXIT")) {
            store_running = false;
            printf("Keluar dari STORE.\n");
        } else {
            printf("Perintah tidak dikenali. Silakan coba lagi.\n");
        }
    }

    /*for (int i = 0; i < listLength(store.barang); i++) {
        free(store.barang.items[i]);
    }
    free(store.barang.items);*/

    return 0;
}
