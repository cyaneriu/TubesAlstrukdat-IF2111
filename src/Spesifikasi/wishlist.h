#ifndef Wishlist
#define Wishlist
#include "../ADT/boolean.h"
#include "../ADT/mesinkata.h"
#include "../ADT/list_dinamis.h"


void wlAdd();
// menambahkan barang ke ujung wishlist

void wlClear();
// menghapus semua barang di wishlist

void wlSwap();
// menukar barang urutan ke-i dan ke-j

void wlRemoveI();
// menghapus barang urutan ke-i

void wlRemove();
// menghapus barang sesuai dengan nama yang diinput

void wlShow();
// menampilkan wishlist

#endif