#include <stdio.h>
#include "../ADT/listlinier.h"

// compile : gcc driver_listlinier.c ../ADT/listlinier.c ../ADT/map.c ../ADT/mesinkata.c ../ADT/mesinkarakter.c -o driver_listlinier

int main() {
    List L1, L2, L3;
    nama_barang item1 = "barang_1";
    nama_barang item2 = "barang_2";
    nama_barang item3 = "barang_3";
    nama_barang deletedItem;

    // test buat list kosong
    CreateEmptyListLinier(&L1);
    CreateEmptyListLinier(&L2);
    printf("List berhasil dibuat.\n");
    // boolean cek list kosong
    if (IsEmptyListLinier(L1)) {
        printf("List L1 dalam keadaan kosong.\n");
    }

    // menambahkan elemen ke awal list
    InsVFirstListLinier(&L1, item1);
    printf("Elemen '%s' ditambahkan ke awal list L1.\n", item1);
    // menambahkan elemen ke akhir list
    InsVLastListLinier(&L1, item2);
    printf("Elemen '%s' ditambahkan ke akhir list L1.\n", item2);

    // print isi list
    printf("Isi list L1 saat ini: ");
    PrintInfoListLinier(L1);
    // print jumlah elemen dalam list
    printf("Jumlah elemen dalam list L1: %d\n", NbElmtListLinier(L1));

    // delete elemen pertama
    DelVFirstListLinier(&L1, &deletedItem);
    printf("Elemen '%s' dihapus dari awal list L1.\n", deletedItem);
    // print isi list setelah penghapusan
    printf("Isi list L1 setelah penghapusan: ");
    PrintInfoListLinier(L1);

    // insert elemen lain untuk pengujian
    InsVLastListLinier(&L1, item3);
    printf("Elemen '%s' ditambahkan ke akhir list L1.\n", item3);
    // print isi list setelah penambahan
    printf("Isi list L1 saat ini: ");
    PrintInfoListLinier(L1);

    // reverse list
    InversListLinier(&L1);
    printf("Isi list L1 setelah dibalik: ");
    PrintInfoListLinier(L1);

    // concat dua list
    InsVFirstListLinier(&L2, item1);
    InsVLastListLinier(&L2, item2);
    printf("Isi list L2: ");
    PrintInfoListLinier(L2);
    KonkatListLinier(&L1, &L2, &L3);
    printf("Isi list L3 (hasil konkatenasi L1 dan L2): ");
    PrintInfoListLinier(L3);

    // swap node
    printf("Melakukan swap node pertama dan kedua pada L3.\n");
    address first = First(L3);
    address second = Next(first);
    SwapNodeListLinier(&L3, first, second);
    // print isi list setelah swap
    printf("Isi list L3 setelah swap: ");
    PrintInfoListLinier(L3);

    return 0;
}
