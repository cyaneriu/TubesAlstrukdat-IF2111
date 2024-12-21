#ifndef WISHLIST_H
#define WISHLIST_H
#include <stdio.h>
#include <stdlib.h>
#include "../ADT/boolean.h"
#include "../ADT/mesinkata.h"
#include "../ADT/list_dinamis.h"
#include "../ADT/listlinier.h"
// #include "./store_list.h"
#include "./store.h"
#include "./load.h"
#include "./work.h"

void driverWL();
// driver untuk mengetes wishlist

void wishlist(User *currentUser, Store *store, Word currentCommand);
// fungsi utama wishlist

int segmentCounter(Word kata);
// menghilangkan spasi sebelum dan sesudah suatu Word

void wlAdd(List *wishlist, ListDin *daftarBarang);
// menambahkan barang ke ujung wishlist

void wlClear(List *wishlist);
// menghapus semua barang di wishlist

void wlSwap(List *wishlist, Word commandWL);
// menukar barang urutan ke-i dan ke-j

void wlRemove(List *wishlist, ListDin *daftarBarang);
// menghapus barang sesuai dengan nama yang diinput

void wlRemoveI(List *wishlist, Word commandWL);
// menghapus barang urutan ke-i

void wlShow(List *wishlist);
// menampilkan wishlist

#endif