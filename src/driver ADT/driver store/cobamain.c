#include <stdio.h>
#include <stdlib.h>
#include "../../spesifikasi/store.h"
#include "../../spesifikasi/store_list.h"
#include "../../spesifikasi/store_request.h"
#include "../../spesifikasi/store_supply.h"
#include "../../spesifikasi/store_supply.h"
#include "../../spesifikasi/store_remove.h"
#include "../../spesifikasi/store_run.h"
#include "../../spesifikasi/load.h"
#include "../../ADT/queue.h"
#include "../../ADT/boolean.h"
#include "../../ADT/list_dinamis.h"
#include "../../ADT/mesinkata.h"
#include "../../ADT/mesinkarakter.h"

int main() {
    Store store;
    createStore(&store);
    loadToStore(&store);

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
            printf("Perintah gagal. Silakan coba lagi.\n");
        }
    }

    return 0;
}
