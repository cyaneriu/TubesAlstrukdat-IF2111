#ifndef Wishlist
#define Wishlist
#include "../ADT/boolean.h"
#include "../ADT/mesinkata.h"
#include "../ADT/list_dinamis.h"
#include "wishlist_ld.h"
#include "./store.h"
#include "./load.h"

void driverWL();
// driver untuk mengetes wishlist

void wishlistTest(List *wishlist, ListDin *daftarBarang);

// void quitTest(int *test);

int segmentCounter(Word kata);
// menghilangkan spasi sebelum dan sesudah suatu Word

//void wlAdd(List *wishlist, ListDin *daftarBarang);
// menambahkan barang ke ujung wishlist

//void wlClear(List *wishlist);
// menghapus semua barang di wishlist

//void wlSwap(List *wishlist, Word commandWL);
// menukar barang urutan ke-i dan ke-j

//void wlRemove(List *wishlist, ListDin *daftarBarang);
// menghapus barang sesuai dengan nama yang diinput

//void wlRemoveI(List *wishlist, Word commandWL);
// menghapus barang urutan ke-i

//void wlShow(List *wishlist);
// menampilkan wishlist

#endif