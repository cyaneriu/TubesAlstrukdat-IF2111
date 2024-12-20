#include <stdio.h>
#include <stdlib.h>
#include "history.h"

void history(User * currentuser, int n) {
    Stack purchased = currentuser->riwayat_pembelian;
    if (IsEmptyStack(purchased)) {
        printf("Kamu belum membeli barang apapun!\n");
        return;
    }
    printf("\nRiwayat pembelian barang:\n");
    
    while (!IsEmptyStack(purchased)) {
        infotypeStack purchasedItem;
        *purchasedItem.name = (char *) malloc((strlen(InfoTop(purchased).name) + 1) * sizeof(char));
        Pop(&purchased, &purchasedItem);
        printf(" Barang: %s Harga: %d\n", purchasedItem.name, purchasedItem.harga);
        free(purchasedItem.name);
    }
}