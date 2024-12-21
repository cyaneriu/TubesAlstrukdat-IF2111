#ifndef Wishlist
#define Wishlist
#include "../ADT/boolean.h"
#include "../ADT/mesinkata.h"
#include "../ADT/list_dinamis.h"
#include "./store.h"
#include "./load.h"

void driverWL();
// driver untuk mengetes wishlist

void wishlistTest(ListDin *wishlist, ListDin *daftarBarang);

// void quitTest(int *test);

int segmentCounter(Word kata);
// menghilangkan spasi sebelum dan sesudah suatu Word

void wlAdd(ListDin *wishlist, ListDin *daftarBarang);
// menambahkan barang ke ujung wishlist

void wlClear(ListDin *wishlist);
// menghapus semua barang di wishlist

void wlSwap(ListDin *wishlist, Word commandWL);
// menukar barang urutan ke-i dan ke-j

void wlRemove(ListDin *wishlist, ListDin *daftarBarang);
// menghapus barang sesuai dengan nama yang diinput

void wlRemoveI(ListDin *wishlist, Word commandWL);
// menghapus barang urutan ke-i

void wlShow(ListDin *wishlist);
// menampilkan wishlist

#endif