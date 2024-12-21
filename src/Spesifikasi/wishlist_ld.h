#ifndef WishlistLD
#define WishlistLD
#include "../ADT/boolean.h"
#include "../ADT/mesinkata.h"
#include "../ADT/list_dinamis.h"
#include "./store.h"
#include "./load.h"

void driverWLLD();
// driver untuk mengetes wishlist

void wishlistTestLD(ListDin *wishlist, ListDin *daftarBarang);

// void quitTest(int *test);

int segmentCounter(Word kata);
// menghilangkan spasi sebelum dan sesudah suatu Word

void wlAddLD(ListDin *wishlist, ListDin *daftarBarang);
// menambahkan barang ke ujung wishlist

void wlClearLD(ListDin *wishlist);
// menghapus semua barang di wishlist

void wlSwapLD(ListDin *wishlist, Word commandWL);
// menukar barang urutan ke-i dan ke-j

void wlRemoveLD(ListDin *wishlist, ListDin *daftarBarang);
// menghapus barang sesuai dengan nama yang diinput

void wlRemoveILD(ListDin *wishlist, Word commandWL);
// menghapus barang urutan ke-i

void wlShowLD(ListDin *wishlist);
// menampilkan wishlist

#endif