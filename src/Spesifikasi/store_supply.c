#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store_supply.h"

// Fungsi untuk memproses supply barang berdasarkan antrian permintaan
void processStoreSupply(Store *store) {
    if (isEmpty(store->barang)) {
        printf("Antrian permintaan kosong.\n");
        return;
    }

    char item[100];
    int price;
    char action[10];

    // Misalnya: kita ambil barang pertama dari antrian
    strcpy(item, ELMT(store->barang, 0));  // Ambil item pertama dari daftar permintaan

    printf("Apakah kamu ingin menambahkan barang %s: ", item);
    scanf("%s", action);

    // Cek apakah tindakan yang diminta adalah "Terima", "Tunda", atau "Tolak"
    if (strcmp(action, "Terima") == 0) {
        printf("Harga barang: ");
        while (scanf("%d", &price) != 1 || price <= 0) {
            printf("Harga harus berupa angka yang lebih besar dari 0!\n");
            while (getchar() != '\n');  // Clear input buffer
        }

        // Menambahkan barang ke dalam toko
        insertLast(&(store->barang), item);
        printf("%s dengan harga %d telah ditambahkan ke toko.\n", item, price);

        // Menghapus barang dari antrian (menggeser elemen dalam daftar)
        free(store->barang.items[0]);  // Hapus barang yang sudah diproses
        for (int i = 0; i < listLength(store->barang) - 1; i++) {
            store->barang.items[i] = store->barang.items[i + 1];
        }
        store->barang.size--;  // Kurangi ukuran daftar
    } 
    else if (strcmp(action, "Tunda") == 0) {
        printf("%s dikembalikan ke antrian.\n", item);
        // Tidak ada perubahan pada antrian (barang tetap di antrian)
    }
    else if (strcmp(action, "Tolak") == 0) {
        printf("%s dihapuskan dari antrian.\n", item);
        // Menghapus barang dari antrian
        free(store->barang.items[0]);
        for (int i = 0; i < listLength(store->barang) - 1; i++) {
            store->barang.items[i] = store->barang.items[i + 1];
        }
        store->barang.size--;  // Kurangi ukuran daftar
    }
    else {
        printf("Tindakan tidak valid.\n");
    }
}
