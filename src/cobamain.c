#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"
#include "../ADT/list_dinamis.h"

void displayMenu() {
    printf("\n=== MENU MANAJEMEN TOKO ===\n");
    printf("1. Tampilkan daftar barang di toko\n");
    printf("2. Tambahkan barang ke toko\n");
    printf("3. Hapus barang dari toko\n");
    printf("4. Tambahkan permintaan barang ke antrian\n");
    printf("5. Proses supply barang dari antrian\n");
    printf("0. Keluar\n");
    printf("Pilih menu: ");
}

int main() {
    Store store;
    createStore(&store);  // Inisialisasi store

    int pilihan;
    char item[100];
    do {
        displayMenu();
        scanf("%d", &pilihan);
        getchar();  // Membersihkan buffer input

        switch (pilihan) {
        case 1:
            // Tampilkan daftar barang
            displayStore(store);
            break;

        case 2:
            // Tambahkan barang ke toko
            printf("Masukkan nama barang yang akan ditambahkan: ");
            fgets(item, 100, stdin);
            item[strcspn(item, "\n")] = '\0';  // Hapus newline dari input
            addItemToStore(&store, item);
            printf("%s berhasil ditambahkan ke toko.\n", item);
            break;

        case 3:
            // Hapus barang dari toko
            printf("Masukkan nama barang yang akan dihapus: ");
            fgets(item, 100, stdin);
            item[strcspn(item, "\n")] = '\0';  // Hapus newline dari input
            removeItemFromStore(&store, item);
            break;

        case 4:
            // Tambahkan permintaan barang ke antrian
            printf("Masukkan nama barang yang diminta: ");
            fgets(item, 100, stdin);
            item[strcspn(item, "\n")] = '\0';  // Hapus newline dari input
            storeRequest(&store, item);
            break;

        case 5:
            // Proses supply barang
            processStoreSupply(&store);
            break;

        case 0:
            printf("Keluar dari program.\n");
            break;

        default:
            printf("Pilihan tidak valid. Silakan pilih menu yang tersedia.\n");
        }
    } while (pilihan != 0);

    // Bebaskan memori yang digunakan
    for (int i = 0; i < listLength(store.barang); i++) {
        free(store.barang.items[i]);
    }
    free(store.barang.items);
    printf("%d", 1);
    return 0;
}
