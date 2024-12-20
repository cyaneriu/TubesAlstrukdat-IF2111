#include <stdio.h>
#include "../ADT/listlinier.h"

int main() {
    List L;
    nama_barang item1 = "barang_1";
    nama_barang item2 = "barang_2";
    nama_barang deletedItem;

    // membuat list kosong
    CreateEmptyListLinier(&L);
    printf("List berhasil dibuat.\n");
    // boolean check list kosong
    if (IsEmptyListLinier(L)){
        printf("List dalam keadaan kosong.\n");
    }
    // insert elemen ke first list
    InsVFirstListLinier(&L, item1);
    printf("Elemen '%s' ditambahkan ke awal list.\n", item1);
    // insert elemen ke last list
    InsVLastListLinier(&L, item2);
    printf("Elemen '%s' ditambahkan ke akhir list.\n", item2);
    // print isi list
    printf("Isi list saat ini: ");
    PrintInfoListLinier(L);
    // print jumlah elemen dalam list
    printf("Jumlah elemen dalam list: %d\n", NbElmtListLinier(L));
    // delete first element dari list
    DelVFirstListLinier(&L, &deletedItem);
    printf("Elemen '%s' dihapus dari awal list.\n", deletedItem);
    // print isi list after ada deletion
    printf("Isi list setelah penghapusan: ");
    PrintInfoListLinier(L);
    // delete last element dari list
    DelVLastListLinier(&L, &deletedItem);
    printf("Elemen '%s' dihapus dari akhir list.\n", deletedItem);
    // print isi list setelah last deletion
    printf("Isi list setelah penghapusan terakhir: ");
    PrintInfoListLinier(L);

    return 0;
}
