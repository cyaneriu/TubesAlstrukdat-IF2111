#include <stdio.h>
#include <stdlib.h>
#include "store_remove.h"
#include "../ADT/mesinkata.h"
#include "store_request.h"
#include "store.h"
#include "../ADT/list_dinamis.h"
#include "../ADT/mesinkata.h"
#include "../ADT/mesinkarakter.h"

/*void storeRemove(Store *store) {
    printf("Nama barang yang akan dihapus: ");
    StartWordInput();

    while (getchar() != '\n'); 
    Word item = currentWord;
    item.TabWord[item.Length] = '\0';

    boolean found = false;

    for (int i = 0; i < listLength(store->barang); i++) {
        if (isEqualWords(currentWord, ELMT(store->barang, i))) {
            found = true;
            char item[100];
            copyFirst(store->barang, item); 
            deleteAt(&(store->barang), item);
            printf("%s telah berhasil dihapus.\n", currentWord.TabWord);
            break;
        }
    }

    if (!found) {
        printf("Toko tidak menjual %s\n", currentWord.TabWord);
    }
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store_remove.h"
#include "../ADT/mesinkata.h"
#include "store_request.h"
#include "store.h"
#include "../ADT/list_dinamis.h"
#include "../ADT/mesinkarakter.h"

void storeRemove(Store *store) {
    printf("Input barang yang akan dihapus: ");
    StartWordInput();
    printf("After input: '%s' (length: %d)\n", currentWord.TabWord, currentWord.Length);
    while (getchar() != '\n'); 
    
    if (currentWord.Length > 0 && currentWord.TabWord[currentWord.Length - 1] == '\n') {
        currentWord.TabWord[currentWord.Length - 1] = '\0';
    }
    printf("Final input: '%s' (length: %d)\n", currentWord.TabWord, currentWord.Length);

    boolean found = false;

    for (int i = 0; i < listLength(store->barang); i++) {
        if (isEqualWords(currentWord, ELMT(store->barang, i))) {
            found = true;
            // Barang ditemukan, hapus barang berdasarkan indeks
            deleteAt(&(store->barang), i);  // Hapus item dari list berdasarkan indeks
            printf("%s telah berhasil dihapus.\n", currentWord.TabWord);  // Menampilkan nama barang yang dihapus
            break;
        }
    }

    if (!found) {
        printf("Toko tidak menjual %s\n", currentWord.TabWord);
    }
}

