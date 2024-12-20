#include <stdio.h>
#include "cart_add.h"

void cartAdd(User *currentUser, ArrayDin item, char *itemName, int itemQty){
    if (itemQty <= 0){
        printf("Jumlah tidak valid!\n");
        return;
    }
    else{
        boolean found = false;
        int idx = SearchArrayDin(item, itemName);

        if(idx == -1){
            printf("Barang ini tidak ada di toko.");
        }
        for (int i = 0; i < currentUser->keranjang.Count; i++){
            Word added = stringToWord(currentUser->keranjang.Elements[i].Key);
            if (isEqualWords(added, itemName)){
                currentUser->keranjang.Elements[i].Value += itemQty;
                found = true;
                break;
            }
        }
        if (!found){
            if (currentUser->keranjang.Count == MaxElm){
                printf("Keranjang kamu sudah penuh!\n");
                return;
            }
            else{
                keytype key;
                CopyStringMap(key, itemName);
                InsertMap(&(currentUser->keranjang), key, itemQty);
            }
        }
        printf("Item berhasil dimasukkan ke keranjang!\n");
    }
}