#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"
#include "../ADT/list_dinamis.h"

void createStore(Store *store) {
    CreateListDin(&(store->barang), 100);
    CreateListDin(&(store->antrian), 100);
}

void addItemToStore(Store *store, char *item) {
    insertLast(&(store->barang), item);
}

void addItemToQueue(Store *store, char *item) {
    insertLast(&(store->antrian), item);
}

void displayStoreMenu() {
    printf("\n=== STORE MENU ===\n");
    printf("1. STORE LIST\n");
    printf("2. STORE REQUEST\n");
    printf("3. STORE SUPPLY\n");
    printf("4. STORE REMOVE\n");
    printf("5. EXIT\n");
}

void store_running() {
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
            displayQueue(store);
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
}