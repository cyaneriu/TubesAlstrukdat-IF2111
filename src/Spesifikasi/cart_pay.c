#include <stdio.h>
#include "cart_pay.h"

void cartPay(User *currentUser){
    int cost = 0;
    ArrayDin Ad;
    if (IsMapEmpty(currentUser->keranjang)){
        printf("Keranjang kosong!\n");
        return;
    }

    printf("Isi keranjang belanja:\n");
    printf("Qty       Nama    Harga\n");

    for (int i = 0; i < currentUser->keranjang.Count; i++){
        char * itemName = (currentUser->keranjang.Elements[i].Key);
        int itemQty = currentUser->keranjang.Elements[i].Value;
        int itemPrice = Ad.A[SearchArrayDin(Ad, itemName)].price;
        int totalItemPrice = itemQty * itemPrice;

        printf("%-10d %-7s %d\n", itemQty, itemName, totalItemPrice);
        cost += totalItemPrice;
    }
    StartCommand();

    printf("Total belanja: %d, checkout? (Checkout/Cancel)\n", cost);
    printf(">> \n");

    if (IsCommandEqual(currentCommand, "Checkout\0")){
        if (currentUser->money < cost){
            printf("Saldo tidak cukup!\n");
            return;
        } else {
            currentUser->money -= cost;
            for (int i = 0; i < currentUser->keranjang.Count; i++){
                char * itemName[100]; copyString(currentUser->keranjang.Elements[i].Key, itemName, stringLen(currentUser->keranjang.Elements[i].Key));
                int itemQty = currentUser->keranjang.Elements[i].Value;
                int itemPrice = Ad.A[SearchArrayDin(Ad, itemName)].price;
                int totalItemPrice = itemQty * itemPrice;

                infotypeStack purchasedItem;
                *purchasedItem.name = (char *)malloc((stringLen(itemName) + 1) * sizeof(char));
                copyString(itemName, purchasedItem.name, stringLen(itemName));
                purchasedItem.harga = totalItemPrice;
                Push(&currentUser->riwayat_pembelian, purchasedItem);
            }
            CreateEmptyMap(&currentUser->keranjang);
            printf("Pembayaran berhasil, sisa saldo: %d\n", currentUser->money);
        }
    } else if (IsCommandEqual(currentCommand, "Cancel\0")){
        printf("Pembayaran dibatalkan.\n");
        return;
    } else {
        printf("Perintah tidak dikenali.\n");
    }
}

