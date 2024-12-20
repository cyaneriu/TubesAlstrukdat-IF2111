#include <stdio.h>
#include "../ADT/stack.h"

int main() {
    Stack S;
    infotypeStack item1, item2, poppedItem;
    // membuat stack kosong
    CreateEmptyStack(&S);
    printf("Stack berhasil dibuat.\n");
    // boolean cek stack kosong
    if (IsEmptyStack(S)) {
        printf("Stack dalam keadaan kosong.\n");
    }
    // insert elemen ke stack
    snprintf(item1.name, MAX_LEN, "Item1");
    item1.harga = 100;
    Push(&S, item1);
    printf("Elemen '%s' dengan harga %d ditambahkan ke stack.\n", item1.name, item1.harga);

    snprintf(item2.name, MAX_LEN, "Item2");
    item2.harga = 200;
    Push(&S, item2);
    printf("Elemen '%s' dengan harga %d ditambahkan ke stack.\n", item2.name, item2.harga);

    // print jumlah elemen di stack
    printf("Jumlah elemen dalam stack: %d\n", NbElmtStack(S));
    // hapus elemen dari stack
    Pop(&S, &poppedItem);
    printf("Elemen '%s' dengan harga %d dihapus dari stack.\n", poppedItem.name, poppedItem.harga);
    // print elemen teratas jika stack tidak kosong
    if (!IsEmptyStack(S)) {
        printf("Elemen teratas: %s dengan harga %d\n", InfoTop(S).name, InfoTop(S).harga);
    }
    return 0;
}