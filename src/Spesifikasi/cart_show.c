#include <stdio.h>
#include "cart_show.h"
#include "../ADT/arraydin.h"

void cartShow(User *currentUser){
    if (IsMapEmpty(currentUser->keranjang)){
        printf("Keranjang kosong!\n");
        return;
    }

    int cost = 0;
    printf("Isi keranjang belanja:\n");
    printf("Qty       Nama    Harga\n");

    for (int i = 0; i < currentUser->keranjang.Count; i++){
        char * itemName; copyString(currentUser->keranjang.Elements[i].Key, itemName, stringLen(currentUser->keranjang.Elements[i].Key));
        int itemQty = currentUser->keranjang.Elements[i].Value;
        int itemPrice = Ad.A[SearchArrayDin(Ad, itemName)].price;
        int totalItemPrice = itemQty * itemPrice;

        printf("%-10d %-7s %d\n", itemQty, itemName, totalItemPrice);
        cost += totalItemPrice;
    }

    printf("Total belanja: %d\n", cost);
}