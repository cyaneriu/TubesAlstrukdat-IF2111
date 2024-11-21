#include <stdio.h>
#include <stdlib.h>
#include "store.h"
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
//void store()
/*int main() {
    Store store;
    createStore(&store);  // Inisialisasi store

    displayStoreMenu();
    StartWordInput();

        if (IsCommandEqual(currentWord, "STORE LIST")){
            displayStore(store);
        } else if (IsCommandEqual(currentWord, "STORE REQUEST")){
            char item[1000];
            printf("Masukkan nama barang: ");
            fgets(item, 100, stdin);
            //StartWordInput();
            //getchar();
            void storeRequest(store)
        } else if (IsCommandEqual(currentWord, "STORE SUPPLY")) {
            storeSupply(store);
        } else if (IsCommandEqual(currentWord, "STORE REMOVE")) {
            removeItemFromStore(&store, currentWord.TabWord);
        } else if (IsCommandEqual(currentWord, "EXIT")) {
        }
            
    // Bebaskan memori yang digunakan
    for (int i = 0; i < listLength(store.barang); i++) {
        free(store.barang.items[i]);
    }
    free(store.barang.items);
    return 0;
}*/
/*
int main() {
    Store store;
    createStore(&store); // Inisialisasi store

    boolean toko = true;

    while (toko) {
        // Tampilkan menu utama
        displayStoreMenu();
        StartWordInput();

        if (IsCommandEqual(currentWord, "STORE LIST")) {
            displayStore(store);
        } else if (IsCommandEqual(currentWord, "STORE REQUEST")) {
            storeRequest(&store);
        } else if (IsCommandEqual(currentWord, "STORE SUPPLY")) {
            storeSupply(&store);
        } else if (IsCommandEqual(currentWord, "STORE REMOVE")) {
            removeItemFromStore(&store);
        } else if (IsCommandEqual(currentWord, "EXIT")) {
            toko = false;
            printf("Keluar dari program.\n");
        } else {
            printf("Perintah tidak dikenali. Silakan coba lagi.\n");
        }
    }

    return 0;
} */
int main() {
    Store store;
    createStore(&store);  // Inisialisasi store

    boolean running = true;

    while (running) {
        // Tampilkan menu utama
        displayStoreMenu();
        StartWordInput(); // Membaca input

        if (IsCommandEqual(currentWord, "STORE LIST")) {
            displayStore(store);
        } else if (IsCommandEqual(currentWord, "STORE REQUEST\0")) {
            

            storeRequest(&store);  // Panggil storeRequest dengan nama barang
        } else if (IsCommandEqual(currentWord, "STORE SUPPLY\0")) {
            storeSupply(&store);
        } else if (IsCommandEqual(currentWord, "STORE REMOVE\0")) {
            StartWordInput();  // Membaca nama barang yang ingin dihapus
            if (currentWord.Length > 0 && currentWord.TabWord[currentWord.Length - 1] == '\n') {
                currentWord.TabWord[currentWord.Length - 1] = '\0';  // Menghapus newline
            }
            removeItemFromStore(&store);
        } else if (IsCommandEqual(currentWord, "EXIT")) {
            running = false;  // Keluar dari loop
            printf("Exiting STORE.\n");
        } else {
            printf("Perintah tidak dikenali. Silakan coba lagi.\n");
        }
    }

    // Bebaskan memori yang digunakan
    for (int i = 0; i < listLength(store.barang); i++) {
        free(store.barang.items[i]);
    }
    free(store.barang.items);

    return 0;
}
