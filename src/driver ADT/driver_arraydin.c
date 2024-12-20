#include <stdio.h>
#include "../ADT/arraydin.h"

int main() {
    ArrayDin Ad = MakeArrayDin();
    printf("ArrayDin berhasil dibuat. Kapasitas awal: %d\n", GetCapacity(Ad));
    for (int i = 0; i < 5; i++){
        Barang item;
        snprintf(item.name, MAX_LEN, "Barang%d", i + 1);
        item.price = (i + 1) * 1000;
        InsertLast(&Ad, item);
        printf("Ditambahkan: %s dengan harga %d\n", item.name, item.price);
    }
    // print isi arraydin
    printf("Isi ArrayDin: \n");
    for (int i = 0; i < Length(Ad); i++){
        Barang item = Get(Ad, i);
        printf("[%d] %s - %d\n", i, item.name, item.price);
    }
    // hapus elemen pertama
    DeleteFirst(&Ad);
    printf("Elemen pertama dihapus.\nIsi ArrayDin setelah penghapusan: \n");
    for (int i = 0; i < Length(Ad); i++){
        Barang item = Get(Ad, i);
        printf("[%d] %s - %d\n", i, item.name, item.price);
    }
    // reverse isi ArrayDin
    ReverseArrayDin(&Ad);
    printf("Isi ArrayDin setelah dibalik: \n");
    for (int i = 0; i < Length(Ad); i++){
        Barang item = Get(Ad, i);
        printf("[%d] %s - %d\n", i, item.name, item.price);
    }
    // dealokasi ArrayDin
    DeallocateArrayDin(&Ad);
    printf("ArrayDin telah didealokasi.\n");

    return 0;
}
