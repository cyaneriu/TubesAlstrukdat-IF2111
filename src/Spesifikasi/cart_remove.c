#include <stdio.h>
#include "cart_remove.h"

void cartRemove(User *currentUser, char *itemName, int itemQty){
    if (itemQty <= 0){
        printf("Jumlah tidak valid!\n");
        return;
    }
    else {
        if (!IsMemberMap(currentUser->keranjang, itemName)){
            printf("Barang ini tidak ada di keranjang.");
            return;
        } else {       
            int idx, qty;
            for(int i = 0; i < currentUser->keranjang.Count; i++){
                if(isEqualWords(stringToWord(currentUser->keranjang.Elements[i].Key), itemName)){
                    idx = i;
                    qty = currentUser->keranjang.Elements[i].Value;
                }
            }     
            if (currentUser->keranjang.Count < itemQty){
                printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", currentUser->keranjang.Elements[idx].Value, itemName);
                DeleteMap(&(currentUser->keranjang), itemName, itemQty);
            } else if (qty == itemQty){
                DeleteMap(&(currentUser->keranjang), itemName, itemQty);
            } else {
                currentUser->keranjang.Elements->Value -= itemQty;
            }
            printf("Item berhasil dihapus dari keranjang!\n");
        }
    }   
}