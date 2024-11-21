#include <stdio.h>
#include <stdlib.h>
#include "spesifikasi/store.h"
#include "spesifikasi/store_list.h"
#include "spesifikasi/store_request.h"
#include "spesifikasi/store_supply.h"
#include "spesifikasi/store_supply.h"
#include "spesifikasi/store_remove.h"
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
    printf("Pilih menu: ");
}

int main() {
    Store store;
    createStore(&store);
    boolean store_running = true;

    while (store_running) {
        displayStoreMenu();
        StartWordInput(); // Membaca input

        if (IsCommandEqual(currentWord, "STORE LIST\0")) {
            displayStore(store);
            printf("\n");
            displayQueue(store);
        } else if (IsCommandEqual(currentWord, "STORE REQUEST\0")) {
            storeRequest(&store);
        } else if (IsCommandEqual(currentWord, "STORE SUPPLY\0")) {
            storeSupply(&store);
        } else if (IsCommandEqual(currentWord, "STORE REMOVE\0")) {
            StartWordInput();
            if (currentWord.Length > 0 && currentWord.TabWord[currentWord.Length - 1] == '\n') {
                currentWord.TabWord[currentWord.Length - 1] = '\0';
            }
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
