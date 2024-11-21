#ifndef STORE_REQUEST_H
#define STORE_REQUEST_H

#include "store.h"

// Fungsi untuk menambah permintaan barang baru ke dalam antrian
boolean isEqualWords(Word word1, char *str);

boolean isItemInStore(Store store, Word item);

boolean isItemInQueue(Store store, Word item);

void storeRequest(Store *store);

#endif
